#ifndef LIGHTS_OUT_H
#define LIGHTS_OUT_H

#include <Arduino.h>
#include <seesaw_neopixel.h>

static constexpr uint32_t COLOR = 0xFF00FF;

/**
 * @brief Return an array of integers (O=off, 1=on)
 *
 * @param board   Pointer to an array of length `length`
 * @param length  Number of lights in the board
*/
void set_board(int* board, uint8_t length);


/**
 * @brief Toggle `idx` and its immediate neighbors [idx–1, idx, idx+1], if valid.
 *
 * @param board   Pointer to the board array
 * @param length  Number of lights in the board
 * @param idx     Index to toggle (0…length–1)
 */
void toggle(int* board, uint8_t length, int idx);


/**
 * @brief True if `idx` is within [0, length).
 *
 * @param idx     Index you are attempting to toggle
 * @param length  Number of lights in the board
 */
bool is_possible_move(uint8_t idx, uint8_t length);


/**
 * @brief Randomly toggle lights `moves` times. Always solvable by reversing.
 *
 * @param board   Pointer to the board array
 * @param length  Number of lights in the board
 * @param moves   Number of random toggles
 */
void randomize_board(int* board, uint8_t length, unsigned moves);


/**
 * @brief Show the board state on a NeoPixel strip.
 *
 * @param board   Pointer to the board array
 * @param length  Number of lights in the board
 * @param strip   Reference to a seesaw_NeoPixel instance
 */
void show_board(int* board, uint8_t length, seesaw_NeoPixel& strip);


/**
 * @brief Returns true only if *all* lights are off.
 *
 * @param board    Pointer to the first int of the board array
 * @param length  Number of lights in the board or on the strip
 */
bool is_solved(int* board, uint8_t length);

#endif