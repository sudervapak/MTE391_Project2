#include "ShaderManager.h"
// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
    std::cout << "Attempting to open file: " << filename << std::endl;
    std::ifstream in(filename, std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    std::cerr << "Error opening file: " << strerror(errno) << std::endl;
    throw std::runtime_error("Unable to open file: " + std::string(filename));
}

ShaderManager::ShaderManager(const char* vertexFile, const char* fragmentFile)
        :vertexShader(0),
         fragmentShader(0),
         shaderProgram(0)
{

    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    // Convert the shader source strings into character arrays
    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();


    // Compile and activate shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);


    glUseProgram(shaderProgram);

}

GLuint ShaderManager::getProgramId() { return shaderProgram; }

ShaderManager::~ShaderManager() {

    glDeleteProgram(shaderProgram);

}
void ShaderManager::run() {

    glUseProgram(shaderProgram);


}