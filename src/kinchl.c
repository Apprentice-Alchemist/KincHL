#include "system.c"
#include "audio/audio.c"
#include "callbacks.c"
#include "compute.c"
#include "display.c"
#include "fileio.c"
#include "image.c"
#include "g4/buffers.c"
#include "g4/constant_location.c"
#include "g4/graphics4.c"
#include "g4/pipeline.c"
#include "g4/render_target.c"
#include "g4/shaders.c"
#include "g4/texture_array.c"
#include "g4/texture_unit.c"
#include "g4/texture.c"
#include "input/gamepad.c"
#include "input/keyboard.c"
#include "input/mouse.c"
#include "input/pen.c"
#include "input/sensor.c"
#include "input/surface.c"
#include "krafix.c"
#include "matrix.c"
#include "window.c"
#undef _COMMAND_LIST
#undef _CONSTANT_BUFFER
#undef _PIPELINE
#undef _RENDER_TARGET
#undef _SHADER
#undef _TEXTURE
#undef _VERTEX_BUFFER
#undef _INDEX_BUFFER
#undef _LOC
#undef _TUNIT
// #include "g5/buffers.c"
// #include "g5/commandlist.c"
// #include "g5/constantbuffer.c"
// #include "g5/graphics5.c"
// #include "g5/pipeline.c"
// #include "g5/texture.c"
// #include "g5/render_target.c"