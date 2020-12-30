/*----------------------------------------------------------------------------
 * Description:   Methods for bridging to an external entity.
 *
 * External Entity:  EV3RawSensors (EV3R)
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

.if ( "EV3HRP" == te_thread.flavor )
#include "ev3api.h"
#include "app.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

static int portMap[] = {0, EV3_PORT_1, EV3_PORT_2, EV3_PORT_3, EV3_PORT_4};

#include "MCLMProject_sys_types.h"

#define numof(table) ((sizeof(table))/(sizeof(table[0])))
/*
 * Bridge:  init_sensor
 */
mclm_result_t
EV3R_init_sensor( const i_t p_port, const int p_type )
{
  assert(p_port >= 0 && p_port <= numof(portMap));
  ER ret = ev3_sensor_config(portMap[p_port],p_type);

  return ((ret == E_OK) ? MCLM_RESULT_OK : MCLM_RESULT_ERROR);

}


/*
 * Bridge:  color_get_color
 */
colorid_t
EV3R_color_get_color( const i_t p_port )
{
  assert(p_port >= 0 && p_port <= numof(portMap));

  return ev3_color_sensor_get_color(portMap[p_port]);
}


/*
 * Bridge:  color_get_reflect
 */
i_t
EV3R_color_get_reflect( const i_t p_port )
{
  assert(p_port >= 0 && p_port <= numof(portMap));

  return ev3_color_sensor_get_reflect(portMap[p_port]);

}


/*
 * Bridge:  color_get_rgb_raw
 */
void
EV3R_color_get_rgb_raw( const i_t p_port, i_t *r, i_t *g, i_t *b )
{
  rgb_raw_t raw;
  assert(p_port >= 0 && p_port <= numof(portMap));

  ev3_color_sensor_get_rgb_raw(portMap[p_port],&raw);
  *r = raw.r;
  *g = raw.g;
  *b = raw.b;
}


/*
 * Bridge:  touch_is_pressed
 */
bool
EV3R_touch_is_pressed( const i_t p_port )
{
  assert(p_port >= 0 && p_port <= numof(portMap));

  return ev3_touch_sensor_is_pressed(portMap[p_port]);
}

.end if
