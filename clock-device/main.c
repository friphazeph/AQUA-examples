
#include "root.h"

typedef struct {
	uvar hour;
	uvar minute;
	uvar second;
	
	uvar day;
	uvar month;
	uvar year; // this is the year since 1900
	
	uvar week_day;
	uvar year_day;
	
} time_device_t;

var main(void) {
	device         clock =                  is_device_supported("clock");
	time_device_t* time  = (time_device_t*) get_device(clock, "current");
	
	print("%lld:%lld:%lld\n", time->hour, time->minute, time->second);
	print("%lld/%lld/%lld\n", time->day,  time->month,  time->year + 1900);
	
	return 0;
	
}
