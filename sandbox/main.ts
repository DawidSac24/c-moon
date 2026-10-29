import * as THREE from "three";
import { SceneManager } from "../src/renderer/core/scene.manager.ts"; // Adjust path as needed
import { Scene } from "../src/index";
import { SandboxScene } from "../src/renderer/scenes/sandbox.scene";
import { PhysicsEngine } from "../src/physics-core/ts/PhysicsEngine.ts";

const physics = new PhysicsEngine();

physics.init().then(() => {
  const result = physics.testAdd(5, 7);
  console.log(`C++ calculated: 5 + 7 = ${result}`);
});

// const physics = new PhysicsEngine();
// physics.init().then(() => {
//   console.log("WASM Physics Loaded in Sandbox!");
//   physics.setGravity(9.81);
// });

const container = document.getElementById("app");
if (!container) throw new Error("No #app container found");

const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
renderer.setSize(window.innerWidth, window.innerHeight);
container.appendChild(renderer.domElement);

window.addEventListener("resize", () => {
  renderer.setSize(window.innerWidth, window.innerHeight);
  if (activeScene) {
    activeScene.camera.aspect = window.innerWidth / window.innerHeight;
    activeScene.camera.updateProjectionMatrix();
  }
});

let activeScene: Scene | null = null;

SceneManager.getInstance()
  .acquireScene("sandbox-scene", async () => {
    const scene = new SandboxScene();

    await scene.load();

    return scene;
  })
  .then((scene) => {
    activeScene = scene;
    activeScene.enter();
  });

let lastTime = performance.now() * 0.001;

function animate(time: number) {
  requestAnimationFrame(animate);

  if (!activeScene) return;

  const timeInSeconds = time * 0.001;
  const deltaTime = timeInSeconds - lastTime;
  lastTime = timeInSeconds;

  activeScene.update(deltaTime);

  renderer.render(activeScene.handle, activeScene.camera);
}

requestAnimationFrame(animate);
