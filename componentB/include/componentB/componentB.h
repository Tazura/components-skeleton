#pragma once

#include <stdint.h>

namespace smp_log
{
typedef struct SLogEntry
{
	uint32_t id;
	
	uint64_t datetime;	
	int32_t priority;
	
	const char *message;	// temporary, should not be stored, should copy the content before next read/write
	const char *code;		// temporary, should not be stored, should copy the content before next read/write
	
} SLogEntry;
}
