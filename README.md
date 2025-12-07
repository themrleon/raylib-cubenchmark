# What is this ?
A simple Raylib graphics FPS benchmark tool, meant to quickly test performance on any platform.

# Compilling
1. Get Raylib's assets for your architecture [here](https://github.com/raysan5/raylib/releases)
2. Compile the tool pointing to where Raylib's headers and libs are
3. Run with `./cubenchmark`

Depending on the graphics backend of your system, step 2 may change:
* PC / x86_64 (DRM / OpenGL 4.6 / MESA)
```bash
gcc -o cubenchmark cubenchmark.c -lraylib -I/home/user/raylib-5.5_linux_amd64/include -L/home/user/raylib-5.5_linux_amd64/lib
```

* Raspberry Pi 1 Model B / ARMv6_32 (Framebuffer / OpenGL ES 2.0)
```bash
gcc -o cubenchmark cubenchmark.c -lraylib -latomic -lbrcmGLESv2 -lbrcmEGL -L/opt/vc/lib
```

# Examples
All using same 320x240 resolution:  

AMD Ryzen 5800H (Raylib 5.5 / OpenGL 4.6):  
<img width="627" height="685" alt="image" src="https://github.com/user-attachments/assets/088039c5-58c8-437f-ad0f-f855b8736738" />

Intel HD 4000 (Raylib 5.5 / OpenGL 4.2):  
![screen](https://github.com/user-attachments/assets/b22caddb-a008-46ae-945a-42f578880ec9)

Raspberry Pi 1 Model B (Raylib 4.5 / OpenGL ES 2.0):  
<img width="652" height="428" alt="image" src="https://github.com/user-attachments/assets/34ee0eca-de7d-4fdf-9e5f-34037cb69b60" />  
<img width="662" height="676" alt="image" src="https://github.com/user-attachments/assets/84b4f807-3272-4c46-9d6e-3331019a63c3" />
> [!WARNING]
> Many devices will cap the FPS to 60fps due to the screen refresh rate, increase that on your device to something large!    
> On raspberry pi edit: `/boot/config.txt` to `hdmi_cvt=320 240 <max FPS> 1 0 0 0`
