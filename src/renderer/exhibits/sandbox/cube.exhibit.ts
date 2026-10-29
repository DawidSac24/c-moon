import * as THREE from "three";
import { Exhibit } from "../exhibit";

// 1. Renamed to match your import in SandboxScene
export class CubeExhibit extends Exhibit {
  private cubeMesh: THREE.Mesh;

  // 2. Added the 'asset' parameter to satisfy your ExhibitBuilder signature
  public constructor(sourceUrl: string, _rawAsset: unknown) {
    const geometry = new THREE.BoxGeometry(1, 1, 1);
    const material = new THREE.MeshStandardMaterial({ color: 0xf59e0b });
    const mesh = new THREE.Mesh(geometry, material);

    super(sourceUrl, mesh);
    this.cubeMesh = mesh;
  }

  public override getMesh(): THREE.Object3D {
    return this.cubeMesh;
  }

  public override update(deltaTime: number): void {
    this.cubeMesh.rotation.x -= deltaTime * 0.5;
    this.cubeMesh.rotation.y += deltaTime * 0.5;
  }

  protected override onDispose(): void {
    // 3. Properly dispose of Three.js data buffers
    this.cubeMesh.geometry.dispose();
    if (Array.isArray(this.cubeMesh.material)) {
      this.cubeMesh.material.forEach((m) => m.dispose());
    } else {
      this.cubeMesh.material.dispose();
    }
  }
}
