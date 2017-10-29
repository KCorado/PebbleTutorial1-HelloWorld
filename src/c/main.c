/*Tutorial 1 - Hello World: main.c file
Kevin Corado, October 29th, 2017
----------------------------------------*/
#include <pebble.h>

//Window 1
Window *window;
TextLayer *text_layer;


//Function for app initialization
void init(){
  //Create the Window
  window = window_create();
  
  //Create the TextLayer, for the display at (0,0),
  // and with a size of 144 x 40
  text_layer = text_layer_create(GRect(0, 0, 144, 40));
  
  //Set the text that will be displayed by the TextLayer
  text_layer_set_text(text_layer, "Hello, World!");
  
  //Add as child layer to be included in rendering
  layer_add_child(window_get_root_layer(window), 
                  text_layer_get_layer(text_layer));
  
  //Push to the stack, animated
  window_stack_push(window, true);
}


//Funcition for app deinitalization
void deinit(){
  //Destroy the TextLayer
  text_layer_destroy(text_layer);
  
  //Destroy the Window
  window_destroy(window);
}


//Main function
//  - Used as starting point for the watchapp
int main(){
  //Initialize the app
  init();
  
  //Wait for app event
  app_event_loop();
  
  //Deinitalize the app
  deinit();
  
  //App finished without error
  return 0;
}

