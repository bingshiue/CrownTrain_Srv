/**
 * @file gl_runtime.h
 *
 */

#ifndef GL_RUNTIME_H_
#define GL_RUNTIME_H_

#define GL_CHECK(x) \
	x; \
	{ \
		GLenum glError = glGetError(); \
		if(glError != GL_NO_ERROR) { \
			fprintf(stderr, "glGetError() = %i (0x%.8x) at %s:%i\n", glError, glError, __FILE__, __LINE__); \
			exit(1); \
		} \
	}

#endif /* GL_RUNTIME_H_ */
