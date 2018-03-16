/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "vehicle.h"

vehicle_t::vehicle_t(ID_t id,
                     const boost::optional<location_t>& start,
                     const boost::optional<location_t>& end)
  : vehicle_t(id, start, end, boost::none) {
}

vehicle_t::vehicle_t(ID_t id,
                     const boost::optional<location_t>& start,
                     const boost::optional<location_t>& end,
                     const boost::optional<amount_t>& capacity)
  : id(id), start(start), end(end), capacity(capacity) {
  if (!static_cast<bool>(start) and !static_cast<bool>(end)) {
    throw custom_exception("No start or end specified for vehicle " +
                           std::to_string(id) + '.');
  }
}

bool vehicle_t::has_start() const {
  return static_cast<bool>(start);
}

bool vehicle_t::has_end() const {
  return static_cast<bool>(end);
}

bool vehicle_t::has_capacity() const {
  return static_cast<bool>(capacity);
}