#version 450 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;
layout (location = 2) in vec2 texture_coord;
layout (location = 3) in float texture_id;

out DATA
{
	vec4 color;
	vec4 position;
	vec2 texture_coord;
	float texture_id;
} vs_out;

uniform mat4 u_model = mat4(1.0);
uniform mat4 u_view = mat4(1.0);
uniform mat4 u_projection;

void main()
{
	gl_Position = u_projection * u_view * u_model * position;
	vs_out.position = u_model * position;
	vs_out.color = color;
	vs_out.texture_coord = texture_coord;
	vs_out.texture_id = texture_id;
}
