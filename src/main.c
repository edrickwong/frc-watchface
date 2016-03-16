#include <pebble.h>

//Pebble UI is like stacks of Windows
//Main Window that everything will sit ontop of
static Window *s_main_window;
//Time layer where the time will be displayed
static TextLayer *s_time_layer;
//Background layer where the FRC logo sits
static BitmapLayer *s_background_layer;
//Bitmap variable for the FRC logo image
static GBitmap *s_background_bitmap;
//Font for the time
static GFont s_time_font;


//function for updating the time
static void update_time() {
//This grabs the time from the system as a blob and sets it to tick_time
time_t temp = time(NULL); 
struct tm *tick_time = localtime(&temp);

// Write the current hours and minutes into a buffer
static char s_buffer[8];
//This line here should actually force the time to display in 24H, will need to fix that
strftime(s_buffer, sizeof(s_buffer), clock_is_24h_style() ? "%H:%M" : "%I:%M", tick_time);
//Sets the text in the textlayer to whatever the time is
text_layer_set_text(s_time_layer, s_buffer);
}

//Tick handler that will be invoked every time the 'minute' changes
static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {

/*************************************************************************************/
/* Key and Value pairs for all the teams**********************************************/
/* This will be used by a dictionary later********************************************/
/* Add team by adding a new KEY_TEAM_[team number] and *VALUE_[team number] pair here*/
/*************************************************************************************/

static const uint32_t KEY_TEAM_254 = 254;
static const char *VALUE_254 = "The Cheesy Poofs";
  
static const uint32_t KEY_TEAM_610 = 610;
static const char *VALUE_610 = "The Coyotes";
  
static const uint32_t KEY_TEAM_746 = 746;
static const char *VALUE_746 = "Gearheads";
  
  static const uint32_t KEY_TEAM_854 = 854;
  static const char *VALUE_854 = "Iron Bears";
  
static const uint32_t KEY_TEAM_857 = 857;
static const char *VALUE_857 = "Superior Roboworks";
  
static const uint32_t KEY_TEAM_907 = 907;
static const char *VALUE_907 = "The Cybernauts";
  
static const uint32_t KEY_TEAM_919 = 919;
static const char *VALUE_919 = "Tiger Techs";
  
static const uint32_t KEY_TEAM_1114 = 1114;
static const char *VALUE_1114 = "Simbotics";
  
static const uint32_t KEY_TEAM_1241 = 1241;
static const char *VALUE_1241 = "THEORY6";
  
static const uint32_t KEY_TEAM_1246 = 1246;
static const char *VALUE_1246 = "Agincourt Lancers";
  
static const uint32_t KEY_TEAM_1305 = 1305;
static const char *VALUE_1305 = "Ice Cubed";
  
static const uint32_t KEY_TEAM_1310 = 1310;
static const char *VALUE_1310 = "RUNNYMEDE ROBOTICS";
  
static const uint32_t KEY_TEAM_1325 = 1325;
static const char *VALUE_1325 = "Inverse Paradox";
  
static const uint32_t KEY_TEAM_1334 = 1334;
static const char *VALUE_1334 = "Red Devils";
  
  static const uint32_t KEY_TEAM_1400= 1360;
  static const char *VALUE_1360="Orbit Robotics"; 
  
static const uint32_t KEY_TEAM_1547 = 1547;
static const char *VALUE_1547 = "Where's Waldo?";
  
static const uint32_t KEY_TEAM_1815 = 1815;
static const char *VALUE_1815 = "Black Scots";
    
static const uint32_t KEY_TEAM_2013 = 2013;
static const char *VALUE_2013 = "Cybergnomes";
  
static const uint32_t KEY_TEAM_2056 = 2056;
static const char *VALUE_2056 = "OP Robotics";
  
  static const uint32_t KEY_TEAM_2200= 2200;
  static const char *VALUE_2200= "MMRambotics";



/*************************************************************************************/
/* Calculate the buffer size that is needed for the final Dictionary******************/
/* uint8_t key_count should be the number of teams in the list ***********************/
/*************************************************************************************/

const uint8_t key_count = 20;

  
/*************************************************************************************/
/* This calculates the size of the dictionary, based on the KEY and VALUE pairs above*/
/* To add a new team, add 'strlen(VALUE_[team number]) + 1' to the list of params*****/  
/*************************************************************************************/
  
const uint32_t size = dict_calc_buffer_size(key_count, strlen(VALUE_610) + 1,
                                           strlen(VALUE_254) + 1,
                                           strlen(VALUE_746) + 1,
                                            strlen(VALUE_854) +1,
                                           strlen(VALUE_857) + 1,
                                           strlen(VALUE_907) + 1,
                                           strlen(VALUE_919) + 1,
                                           strlen(VALUE_1114) + 1,
                                           strlen(VALUE_1241) + 1,
                                           strlen(VALUE_1246) + 1,
                                           strlen(VALUE_1305) + 1,
                                           strlen(VALUE_1310) + 1,
                                            strlen(VALUE_1360)+ 1,
                                           strlen(VALUE_1325) + 1,
                                           strlen(VALUE_1334) + 1,
                                           strlen(VALUE_1547) + 1,
                                           strlen(VALUE_1815) + 1,
                                           strlen(VALUE_2013) + 1,
                                           strlen(VALUE_2056) + 1,
                                            strlen(VALUE_2200) + 1) ;
  

  
// Stack-allocated buffer in which to create the Dictionary:
uint8_t buffer[size];

// Iterator variable, keeps the state of the creation serialization process:
DictionaryIterator iter;

// Begin:
dict_write_begin(&iter, buffer, sizeof(buffer));
/*************************************************************************************/
/* This adds a KEY and VALUE pair to the dictionary***********************************/
/* Add team based by appending dict_write_cstring(&iter, KEY_TEAM_[team number], VALUE_[team number]);*/
/*************************************************************************************/
  
dict_write_cstring(&iter, KEY_TEAM_254, VALUE_254);  
dict_write_cstring(&iter, KEY_TEAM_610, VALUE_610);
dict_write_cstring(&iter, KEY_TEAM_746, VALUE_746);
dict_write_cstring(&iter, KEY_TEAM_854, VALUE_854);
dict_write_cstring(&iter, KEY_TEAM_857, VALUE_857);
dict_write_cstring(&iter, KEY_TEAM_907, VALUE_907);
dict_write_cstring(&iter, KEY_TEAM_919, VALUE_919);
dict_write_cstring(&iter, KEY_TEAM_1114, VALUE_1114);
dict_write_cstring(&iter, KEY_TEAM_1241, VALUE_1241);
dict_write_cstring(&iter, KEY_TEAM_1246, VALUE_1246);
dict_write_cstring(&iter, KEY_TEAM_1305, VALUE_1305);
dict_write_cstring(&iter, KEY_TEAM_1310, VALUE_1310);
dict_write_cstring(&iter, KEY_TEAM_1325, VALUE_1325);
dict_write_cstring(&iter, KEY_TEAM_1334, VALUE_1334);
  dict_write_cstring(&iter, KEY_TEAM_1400, VALUE_1360);
dict_write_cstring(&iter, KEY_TEAM_1547, VALUE_1547);
dict_write_cstring(&iter, KEY_TEAM_1815, VALUE_1815);
dict_write_cstring(&iter, KEY_TEAM_2013, VALUE_2013);
dict_write_cstring(&iter, KEY_TEAM_2056, VALUE_2056);
dict_write_cstring(&iter, KEY_TEAM_2200, VALUE_2200);

// End:

//Calculates the final size of the dictionary
const uint32_t final_size = dict_write_end(&iter);
//This sets up a tuple that will be used to iterate through the dictionary
Tuple *tuple = dict_read_begin_from_buffer(&iter, buffer, final_size);
//Logic for figuring out if the time matches a team number
while (tuple) {
  //A really big buffer for the team name
  static char s_buffer[64];
  
  //snprintf(s_buffer, sizeof(s_buffer), "%s", tuple->value->cstring);
  
  //Rips the current time measurement into hours and minutes
  //Multiples the hour by 100 to shift it to the correct digit
  //and then adds it to the minutes to form the correct FRC four digit team number
  //For example, if the time is 11:14, then this takes the 11 (hours), multiplies it by 100 to get 1100
  //and adds it to 14 (minutes) to get 1114, which is compared to all the keys in the dictionary (team numbers)
  if(tick_time->tm_hour*100+tick_time->tm_min == (int)tuple->key){
    //Debug stuff
    APP_LOG(APP_LOG_LEVEL_DEBUG, "this ran");
    //This writes the team name to the really big string buffer
    snprintf(s_buffer, sizeof(s_buffer), "%s", tuple->value->cstring);
    //More debug stuff
    APP_LOG(APP_LOG_LEVEL_DEBUG, "this ran 2");
    //This sets the font to a smaller sized font relative to the time font
    //Because teams have long names
    text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
    //This sets the text to the team name
    text_layer_set_text(s_time_layer, s_buffer);
    //Even more debug stuff
    APP_LOG(APP_LOG_LEVEL_DEBUG, "this ran 3");
    
    //Vibrates if time == team number
    vibes_long_pulse();
    //Breaks out of the while loop, do it stops when the correct team is found
    //and doesn't continue checking the rest of the dictionary
    break;

  }else{
    //If time doesn't match any team numbers, just updates time normally
    
    //This resets the time font back to normal
    text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
    update_time();
    //Debug stuff
    APP_LOG(APP_LOG_LEVEL_DEBUG, "this did no run");
  }
  //Goes to the next dictionary item
  tuple = dict_read_next(&iter);
  }
  
}

//This function loads everything into the base window
static void main_window_load(Window *window) {
  // Get information about the Window
  Layer *window_layer = window_get_root_layer(window);
  //Finds the boundary for the Window, which is pretty much the size of the screen in this case
  GRect bounds = layer_get_bounds(window_layer);

  // Create GBitmap
  s_background_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_BACKGROUND_NEWER);

  // Create BitmapLayer to display the GBitmap
  s_background_layer = bitmap_layer_create(GRect(0, PBL_IF_ROUND_ELSE(5, 1), bounds.size.w, 110));

  // Set the bitmap onto the layer and add to the window
  bitmap_layer_set_bitmap(s_background_layer, s_background_bitmap);
  //GCompSet is the param that sets the transparency in a png
  bitmap_layer_set_compositing_mode(s_background_layer, GCompOpSet);
  //Adds the png to the background layer
  layer_add_child(window_layer, bitmap_layer_get_layer(s_background_layer));

  // Create the TextLayer with specific bounds
  s_time_layer = text_layer_create(
      GRect(0, /*PBL_IF_ROUND_ELSE(58, 52)*/ 110, bounds.size.w, 150));

  // Improve the layout to be more like a watchface
  
  //This makes the background for the text layer clear
  //So the base Window background can show through
  text_layer_set_background_color(s_time_layer, GColorClear);
  //Time text colour
  text_layer_set_text_color(s_time_layer, GColorRed);
  //Default placeholder/backfall if time doesn't show up
  text_layer_set_text(s_time_layer, "ballsohard");
  //Centers time text
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  //Sets time text font
  text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  //This wraps the text for the team names if it is too long
  text_layer_set_overflow_mode(s_time_layer, GTextOverflowModeWordWrap);
  //text_layer_set_font(s_time_layer, fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD));
  // Create GFont
  //s_time_font = fonts_load_custom_font(resource_get_handle(FONT_KEY_BITHAM_42_BOLD));

  // Apply to TextLayer
  //text_layer_set_font(s_time_layer, s_time_font);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
}

//This function is needed when the watchface is exited to free up resources on the watch
static void main_window_unload(Window *window) {
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);

  // Unload GFont
  fonts_unload_custom_font(s_time_font);

  // Destroy GBitmap
  gbitmap_destroy(s_background_bitmap);

  // Destroy BitmapLayer
  bitmap_layer_destroy(s_background_layer);
}

//Initialization/ setup function
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set the background color
  window_set_background_color(s_main_window, GColorWhite);

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);

  // Make sure the time is displayed from the start
  update_time();

  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
}

//Teardown function
static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
}

//Main Function
int main(void) {
  init();
  app_event_loop();
  deinit();
}