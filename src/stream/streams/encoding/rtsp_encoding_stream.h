/*  Copyright (C) 2014-2020 FastoGT. All right reserved.
    This file is part of fastocloud.
    fastocloud is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    fastocloud is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with fastocloud.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "stream/streams/encoding/encoding_stream.h"

namespace fastocloud {
namespace stream {
namespace elements {
namespace sources {
class ElementRTSPSrc;
}
}  // namespace elements
namespace streams {

namespace builders {
class RtspEncodingStreamBuilder;
}

class RtspEncodingStream : public EncodingStream {
  friend class builders::RtspEncodingStreamBuilder;

 public:
  RtspEncodingStream(const EncodeConfig* config, IStreamClient* client, StreamStruct* stats);
  const char* ClassName() const override;

 protected:
  IBaseBuilder* CreateBuilder() override;

  virtual void OnRTSPSrcCreated(elements::sources::ElementRTSPSrc* src);
  virtual void HandleRtspSrcPadAdded(GstElement* src, GstPad* new_pad);

 private:
  static void rtspsrc_pad_added_callback(GstElement* src, GstPad* new_pad, gpointer user_data);
};

}  // namespace streams
}  // namespace stream
}  // namespace fastocloud
