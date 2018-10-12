
#include "root.h"
#include "lib/internet/weather.h"

var main(void) {
	weather_t weather;
	
	if (new_weather(&weather)) {
		print("WARNING Failed create weather object\n");
		return true;
		
	}
	
	if (weather_update(&weather, WEATHER_NOW)) {
		print("WARNING Failed to update weather data\n");
		return true;
		
	}
	
	print("Temperature: %lld deg %c\n", weather.temperature, weather.unit);
	
	dispose_weather(&weather);
	return false;
	
}
