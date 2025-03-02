/*****ジャックと木*****/

 #define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
 #include <SDL3/SDL.h>
 #include <SDL3/SDL_main.h>
 #include <string>
 
    using namespace std;

 /* We will use this renderer to draw into this window every frame. */
 static SDL_Window *window = NULL;
 static SDL_Renderer *renderer = NULL;
 
 /* This function runs once at startup. */
 SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
 {
    string str = "Jack and Tree";
     SDL_SetAppMetadata(str.c_str(), "0.1", "jackandtree");
 
     if (!SDL_Init(SDL_INIT_VIDEO)) {
         SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
         return SDL_APP_FAILURE;
     }
 
     if (!SDL_CreateWindowAndRenderer("Jack and Tree", 768, 1024, 0, &window, &renderer)) {
         SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
         return SDL_APP_FAILURE;
     }
 
     return SDL_APP_CONTINUE;  /* carry on with the program! */
 }
 
 /* This function runs when a new event (mouse input, keypresses, etc) occurs. */
 SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
 {
     if (event->type == SDL_EVENT_QUIT) {
         return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
     }
     return SDL_APP_CONTINUE;  /* carry on with the program! */
 }
 
 /* This function runs once per frame, and is the heart of the program. */
 SDL_AppResult SDL_AppIterate(void *appstate)
 {
     const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */

     /* clear the window to the draw color. */
     SDL_RenderClear(renderer);
 


     /* put the newly-cleared rendering on the screen. */
     SDL_RenderPresent(renderer);
 
     return SDL_APP_CONTINUE;  /* carry on with the program! */
 }
 
 /* This function runs once at shutdown. */
 void SDL_AppQuit(void *appstate, SDL_AppResult result)
 {
     /* SDL will clean up the window/renderer for us. */
 }