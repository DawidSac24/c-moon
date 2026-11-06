# c-moon

A high-performance, N-body physics engine written in C++17 and compiled to WebAssembly (Wasm). Designed to serve as the computational backend for a Three.js / React 3D portfolio.

## Architecture

`c-moon` is built on a decoupled submodule architecture:

- **Physics Core (C++):** Handles linear algebra, numerical integration, and gravity calculations using Newton's Law of Universal Gravitation.
- **Wasm Bridge (Embind):** Exposes C++ classes directly to JavaScript/TypeScript.
- **Sandbox Environment (Vite + Three.js):** A lightweight, standalone web environment to visually test the physics engine without React overhead.

## Dependencies

1. **Node.js & npm:** For the Vite sandbox and build scripts.
2. **C++17 Compiler:** (`g++` or `clang`) for running native terminal tests.
3. **Emscripten SDK (emsdk):** The C++ to WebAssembly compiler toolchain.

## Setup & Installation

### 1. Install Node Dependencies

```bash
npm install
```

### 2. Install Emscripten (emsdk)

WebAssembly compilation requires the Emscripten toolchain. If you haven't installed it on your machine yet, run this in a global tools directory (not inside this repo):

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
```

### 3. Automate Emscripten (Recommended)

By default, Emscripten does not add itself to your system path. To make the `em++` command available automatically every time you open a terminal, add the environment script to your shell profile:

**For Zsh (Mac / Modern Linux):**

```bash
echo 'source /path/to/emsdk/emsdk_env.sh > /dev/null 2>&1' >> ~/.zshrc
source ~/.zshrc
```

**For Bash (Linux / WSL):**

```bash
echo 'source /path/to/emsdk/emsdk_env.sh > /dev/null 2>&1' >> ~/.bashrc
source ~/.bashrc
```

_(Note: Replace `/path/to/emsdk/` with the actual path where you cloned the repository)._

## Compiling & Running

The project includes `npm` scripts to handle the complex C++ compilation flags automatically.

### Build the WebAssembly Module

Compiles the C++ source code and outputs `physics.js` and `physics.wasm` into the `src/physics-core/wasm/` directory.

```bash
npm run build
```

### Run the Sandbox

Starts a local Vite development server to test the WebAssembly engine in the browser with Three.js.

```bash
npm run dev
```

### Run Native Physics Tests

Compiles and runs the engine purely in the terminal using `g++`. Useful for debugging memory leaks, segfaults, or core math without involving the browser.

```bash
npm run test:physics
```

## Directory Structure

```text
c-moon/
├── sandbox/               # Standalone Vite/Three.js test environment
├── src/
│   ├── physics-core/
│   │   ├── cpp/           # C++ Source and Headers (math, core, forces)
│   │   ├── ts/            # TypeScript wrappers for the Wasm module
│   │   └── wasm/          # Generated build output (.js, .wasm)
│   └── renderer/          # WebGL graphics engine
└── package.json           # Build scripts
```
