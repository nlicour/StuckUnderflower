#ifndef REMOTE_H_
#define REMOTE_H_

#include <cstdint>

class RemoteSystem;

namespace remote
{
RemoteSystem* create_system();
void destroy_system(RemoteSystem*);
bool connect(RemoteSystem*, uint32_t remote_id);
uint16_t get_remote_state(RemoteSystem*, uint32_t remote_id);
void toggle_led(RemoteSystem*, uint8_t led);
} // namespace anonymous

#endif // REMOTE_H_


