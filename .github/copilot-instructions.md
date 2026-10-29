# Copilot instructions

## Build and verification

- `npm run dev` starts the Vite sandbox; open the local URL it prints. The root `index.html` loads `sandbox/main.ts`.
- `npm run build` runs `npm run build:wasm`, which uses Emscripten to compile `src/physics-core/add.cpp` and `src/physics-core/bindings.cpp` into the embind module at `public/physics-core.js`. This requires the Emscripten toolchain (`em++`).
- `npm run test:physics` compiles the native C++ addition test with `g++` and runs it; it does not require Emscripten.
- `npx tsc --noEmit` runs the strict TypeScript check configured by `tsconfig.json`.
- No test runner, test files, or lint script are configured in `package.json`, so there is no repository command for running the full suite or an individual test.

## Architecture

- `src/index.ts` is the package's public export surface. Renderer code is organized under `src/renderer`: scenes own exhibits and post-processing effects, exhibits wrap Three.js objects, and decorators compose additional exhibit behavior.
- `Scene` defines the lifecycle (`load`, `enter`, `update`, `exit`, `dispose`), owns the Three.js scene/camera, and forwards updates and disposal to its exhibits and effects. `EngineCore` handles rendering, resize, and scene switching; `SceneManager` is a separate singleton for acquiring cached scenes. The Vite sandbox currently has its own renderer/animation loop and acquires `SandboxScene` through `SceneManager`.
- `ExhibitBuilder` acquires an asset before constructing a base exhibit, then wraps it with the requested decorators. `AssetManager` selects a Three.js loader by URL extension and stores loaded assets in a reference-counted cache. Exhibits release their source URL on disposal; the manager disposes Three.js resources when the reference count reaches zero. Scene caches use LRU eviction and dispose evicted scenes.
- Effects implement `PostProcessEffect` and expose a Three.js post-processing `Pass`; scene updates and effect resizing/input are intended to be driven through that interface. Shader sources are imported by Vite with `?raw`.

## Repository-specific conventions

- Keep TypeScript compatible with the strict, no-emit configuration in `tsconfig.json` (`strict`, `noUnusedLocals`, `noUnusedParameters`, and `noFallthroughCasesInSwitch`). The project uses ES modules and bundler resolution; Vite-specific imports such as shader `?raw` are part of the build setup.
- New scenes should extend `Scene`, assemble their lights/exhibits/effects during `load()`, and use the lifecycle hooks rather than creating a second rendering loop. New exhibits extend `Exhibit`, implement `update()` and `onDispose()`, and release their source asset through the base `dispose()` implementation.
- Exhibit decorators extend `ExhibitDecorator` and forward behavior to the wrapped exhibit. Keep the wrapper's shared mesh and update/disposal delegation intact when adding decorators.
- Asset loading is extension-based: register a loader with `AssetManager` for any new asset extension. Keep resource ownership aligned with the cache's acquire/release lifecycle; do not dispose a shared cached asset directly from an exhibit.
- Use the `ThreeParser` type guards when handling loader results or traversing unknown Three.js values. Support GLTF assets that expose a `.scene` as well as direct `Object3D` loader results.
