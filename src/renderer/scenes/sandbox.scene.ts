import * as THREE from "three";
import { ExhibitBuilder } from "../builders/exhibit.builder";
import { CubeExhibit } from "../exhibits/sandbox/cube.exhibit";
import { Scene } from "./scene";

export class SandboxScene extends Scene {
  public override async load(): Promise<void> {
    this.camera.position.z = 5;

    const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
    const directionalLight = new THREE.DirectionalLight(0xffffff, 1.0);
    directionalLight.position.set(5, 5, 5);
    this.handle.add(ambientLight, directionalLight);

    const cube = new CubeExhibit("procedural-cube", null);

    this.addExhibit(cube);
  }

  public override enter(): void {}
  public override exit(): void {}
  protected override onUpdate(_deltaTime: number): void {}
  protected override onDispose(): void {}
}
