#version 450 core

out vec4 color;

in DATA
{
	vec4 color;
	vec4 position;
	vec2 texture_coord;
	float texture_id;
} fs_in;

uniform vec4 u_light_position;
uniform sampler2D u_textures[32];

void main()
{
	float intensity = 100.0f / length(fs_in.position.xy - u_light_position.xy);
	intensity = 1.0f;
	if (fs_in.texture_id > 0.0) {
		int texture_id = int(fs_in.texture_id);
		vec4 tex_color = texture(u_textures[texture_id], fs_in.texture_coord);
		// if (intensity < 0.5f) {
		// 	color = fs_in. * tex_color * intensity;
		// }
		// else {
		// 	color = fs_in.color * tex_color;
		// }
		if (fs_in.color.a == 0.99f) { // font texture
			color = vec4(tex_color.r * fs_in.color.r, tex_color.r * fs_in.color.g, tex_color.r * fs_in.color.b, tex_color.r * (fs_in.color.a + 0.01f)) * intensity; // only texture without color
		}
		else if (fs_in.color == vec4(0, 0, 0, 0)) { // normal texture
			color = tex_color * intensity;
		}
		else {
			color = fs_in.color * tex_color * intensity; // with texture and color
		}
	}
	else {
		color = fs_in.color * intensity; // only color without texture
	}
}
