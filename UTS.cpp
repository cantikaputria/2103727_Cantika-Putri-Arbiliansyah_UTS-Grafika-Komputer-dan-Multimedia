//  Nama    : Cantika Putri Arbiliansyah
//  NIM     : 2103727
//  Ujian Tengah Semester Grafika Komputer dan Multimedia

//LIBRARY
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "shader_s.h"
#include <iostream>

//WINDOWS
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

//PENGATURAN UKURAN
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//PROSES
int main()
{
    //INISIALISASI DAN KONFIGURASI GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //MEMBUAT WINDOW
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "2103727_Cantika Putri Arbiliansyah_UTS", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //MENAMPILKAN WINDOW
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //GLAD: memulai semua fungsi pointers dari OpenGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //BUILD AND COMPILE SHADER PROGRAM
    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");


    //SET UP VERTEX, COLOR, dan TEXTURE
    float vertices[] = {
        //MEMBUAT BACKGROUND DENGAN TEXTURE
       -1.0f, -1.0f, 0.0f,      1.0f, 1.0f, 1.0f,       0.0f, 0.0f,
       -1.0f, 1.0f, 0.0f,       1.0f, 1.0f, 1.0f,       0.0f, 1.0f,
        1.0f, -1.0f, 0.0f,      1.0f, 1.0f, 1.0f,       1.0f, 0.0f,

       -1.0f, 1.0f, 0.0f,       1.0f, 1.0f, 1.0f,       0.0f, 1.0f,
        1.0f, -1.0f, 0.0f,      1.0f, 1.0f, 1.0f,       1.0f, 0.0f,
        1.0f, 1.0f, 0.0f,       1.0f, 1.0f, 1.0f,       1.0f, 1.0f,
        
        /* BURUNG KIRI */
        //SAYAP KANAN
        //EIG
        -0.5f, 0.9f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.2f, 0.99f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.3f, 0.7f, 0.0f,       0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //ECG
        -0.5f, 0.9f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.5f, 0.6f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.3f, 0.7f, 0.0f,       0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //AEC
        -0.6f, 0.8f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.5f, 0.9f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.5f, 0.6f, 0.0f,       0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //BADAN
        //ACB
        -0.6f, 0.8f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.5f, 0.6f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.7f, 0.6f, 0.0f,       0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //BCJ
        -0.7f, 0.6f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.5f, 0.6f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.6f, 0.25f, 0.0f,      0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //JKL
        -0.6f, 0.25f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.65f, 0.05f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.55f, 0.05f, 0.0f,      0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //SAYAP KIRI
        //DFH
        -0.7f, 0.9f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.9f, 0.7f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.99f,0.99f, 0.0f,      0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //DFB
        -0.7f, 0.9f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.9f, 0.7f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.7f, 0.6f, 0.0f,      0.7f, 0.7f, 0.7f,       0.0f, 0.0f,

        //DAB
        -0.7f, 0.9f, 0.0f,     0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.6f, 0.8f, 0.0f,     0.6f, 0.6f, 0.6f,       0.0f, 0.0f,
        -0.7f, 0.6f, 0.0f,     0.7f, 0.7f, 0.7f,       0.0f, 0.0f,
       
        /* BURUNG TENGAH */
        //SAYAP KANAN
        //EIG
        0.1f, 0.3f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.4f, 0.4f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.3f, 0.1f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //ECG
        0.1f, 0.3f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.1f, 0.0f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.3f, 0.1f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //AEC
        0.0f, 0.2f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.1f, 0.3f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.1f, 0.0f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //BADAN
        //ACB
        0.0f, 0.2f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.1f, 0.0f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.1f, 0.0f, 0.0f,       0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //BCJ
       -0.1f, 0.0f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.1f, 0.0f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.0f, -0.4f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //JKL
        0.0f, -0.4f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.05f, -0.6f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.05f, -0.6f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //SAYAP KIRI
        //DFH
       -0.1f, 0.3f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.3f, 0.1f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.4f, 0.4f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

       //DFB
       -0.1f, 0.3f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.3f, 0.1f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.1f, 0.0f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        //DAB
       -0.1f, 0.3f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
        0.0f, 0.2f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
       -0.1f, 0.0f, 0.0f,      0.6f, 0.6f, 0.6f,       0.0f, 0.0f,

        /* BURUNG KANAN */
        //SAYAP KANAN
        //EIG
        0.5f, 0.9f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.2f, 0.99f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.3f, 0.7f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //ECG
        0.5f, 0.9f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.5f, 0.6f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.3f, 0.7f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //AEC
        0.6f, 0.8f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.5f, 0.9f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.5f, 0.6f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //BADAN
        //ACB
        0.6f, 0.8f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.5f, 0.6f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.7f, 0.6f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //BCJ
        0.7f, 0.6f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.5f, 0.6f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.6f, 0.25f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //JKL
        0.6f, 0.25f, 0.0f,        0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.65f, 0.05f, 0.0f,       0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.55f, 0.05f, 0.0f,       0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //SAYAP KIRI
        //DFH
        0.7f, 0.9f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.9f, 0.7f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.99f,0.99f, 0.0f,     0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //DFB
        0.7f, 0.9f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.9f, 0.7f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.7f, 0.6f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,

        //DAB
        0.7f, 0.9f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.6f, 0.8f, 0.0f,      0.4f, 0.4f, 0.4f,       0.0f, 0.0f,
        0.7f, 0.6f, 0.0f,      0.5f, 0.5f, 0.5f,       0.0f, 0.0f,
    };

    //DEKLARASI BUFFER OBJEK
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    stbi_set_flip_vertically_on_load(true);

    //BIND VAO
    glBindVertexArray(VAO);

    //BIND VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //KONFIGURASI ATRIBUT VERTEX
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //ATRIBUT POSISI
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //ATRIBUT WARNA
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //ATRIBUT KOORDINAT TEXTURE
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    //MEMBUAT TEXTURE
    unsigned int texture;

    //SET ID VARIABEL
    glGenTextures(1, &texture);

    //BINDING VARIABEL DENGAN TIPE TEXTURE
    glBindTexture(GL_TEXTURE_2D, texture);

    //SET PARAMETER TEXTURE WRAPPING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //SET PARAMETER TEXTURE FILTERING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //LOAD IMAGE, MEMBUAT TEXTURE, DAN MIPMAPS
    int width, height, nrChannels;

    //INPUT FILE GAMBAR SESUAI LOKASI FILE
    unsigned char *data = stbi_load("./image.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        //generate texture image
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //generate mipmap
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    //MENGHAPUS DARA
    stbi_image_free(data);

    //RENDER LOOP
    while (!glfwWindowShouldClose(window))
    {
        //INPUT WINDOW
        processInput(window);

        //RENDER WARNA WINDOW
        glClearColor(0.1f, 0.3f, 0.4f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //BIND TEXTURE
        glBindTexture(GL_TEXTURE_2D, texture);

        //RENDER SHADER
        ourShader.use();

        //RENDER SHADER
        float geser = tan (glfwGetTime()) * 0.100;
        int posisi = glGetUniformLocation(ourShader.ID, "Geser");
        glUniform1f(posisi, geser);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 900);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-alokasi semua sumber daya setelah mereka mencapai tujuannya
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    // glfw: mengakhiri, membersihkan semua sumber daya GLFW yang dialokasikan sebelumnya.
    glfwTerminate();
    return 0;
}

// proses semua input: tanyakan GLFW apakah tombol yang relevan ditekan/dilepas bingkai ini dan bereaksi sesuaivoid processInput(GLFWwindow *window)
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: setiap kali ukuran jendela diubah (oleh OS atau pengubahan ukuran pengguna) fungsi panggilan balik ini dijalankan
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // pastikan viewport cocok dengan dimensi jendela baru; perhatikan bahwa lebar dan
    // tinggi akan jauh lebih besar dari yang ditentukan pada tampilan retina.
    glViewport(0, 0, width, height);
}