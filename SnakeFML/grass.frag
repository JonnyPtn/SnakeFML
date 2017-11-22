void main(void)
{
	vec2 coord = gl_TexCoord[0].xy;
    
    vec3 colour = vec3(0,1,0);
	gl_FragColor = vec4(colour, 1.0);
}
