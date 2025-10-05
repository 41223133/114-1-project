// Wokwi Custom Chip - For docs and examples see:
// https://docs.wokwi.com/chips-api/getting-started
//
// SPDX-License-Identifier: MIT
// Copyright 2023 曹祐豪

// Input / output names must match the pins defined in the chip's JSON file:
module wokwi (
  input wire IN,
  output wire OUT
  );

  // put your logic here, e.g.:
  assign OUT = ~IN;

endmodule