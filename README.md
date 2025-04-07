# 📌 FDF – Wireframe Renderer (42 Project)


**FDF** is a 3D wireframe rendering program written in **C**, using **MiniLibX**, developed as part of the **School 42 curriculum**. It reads a 3D height map from a file and projects it onto a 2D screen using **isometric projection**.

> ✅ This implementation includes only the mandatory part: map parsing, basic rendering with isometric projection, zoom, pan, and line drawing via **Bresenham’s algorithm**.

---

## 🧠 Key Concepts & What I Learned

### 🔹 Data Structures
- **Dynamic 2D arrays** to store map height data (`z-values`)
- **Structs** to represent points, vectors, and rendering context
- Manual memory allocation and deallocation (no garbage collector!)

### 🔹 Algorithms
- **Bresenham’s Line Algorithm**: Efficient way to draw lines between 2 points using only integer math.
- **Isometric Projection**: A 3D to 2D projection formula giving depth and perspective to flat maps.
- Coordinate transformations (translation, scaling, projection)

### 🔹 Graphics Programming
- Use of **MiniLibX**, a minimal graphics library for window creation and pixel rendering.
- Working with pixels, buffers, and screen refreshes.
- Handling keyboard input events (arrows, zoom, ESC).
