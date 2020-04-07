#version 330 core
in vec4 aPosition;
in vec4 aTextColor;
out vec4 outTextColor;
void main()
{
   gl_Position = aPosition;
   outTextColor = aTextColor;
};
