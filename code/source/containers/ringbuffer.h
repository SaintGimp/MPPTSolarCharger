// Adapted from https://github.com/AndersKaloer/Ring-Buffer/

#include <inttypes.h>

#ifndef RINGBUFFER_H
#define RINGBUFFER_H

// The size of a ring buffer.
// Due to the design only <tt> RING_BUFFER_SIZE-1 </tt> items
// can be contained in the buffer.
// The buffer size must be a power of two.
#define RING_BUFFER_SIZE 128

#if (RING_BUFFER_SIZE & (RING_BUFFER_SIZE - 1)) != 0
#error "RING_BUFFER_SIZE must be a power of two"
#endif

// The type which is used to hold the size
// and the indicies of the buffer.
// Must be able to fit \c RING_BUFFER_SIZE .
using RingBufferSize = uint8_t;

// Used as a modulo operator as a % b = (a & (b − 1))
// where a is a positive index in the buffer and
// b is the (power of two) size of the buffer.
#define RING_BUFFER_MASK (RING_BUFFER_SIZE - 1)

class RingBuffer
{
    public:
        RingBuffer()
        {
            Reset();
        }
        
        // Empties/resets the ring buffer.
        void Reset();

        // Adds a byte to the ring buffer.
        void Queue(char data);

        // Adds an array of bytes to the ring buffer.
        void Queue(const char* data, RingBufferSize size);

        // Returns the oldest byte in the ring buffer.
        bool Dequeue(char* data);

        // Returns the oldest bytes in the ring buffer.
        RingBufferSize Dequeue(char* data, RingBufferSize size);

        // Peeks a ring buffer, i.e. returns an element without removing it.
        bool Peek(char* data, RingBufferSize index);
        
        // Returns whether the ring buffer is empty.
        bool IsEmpty()
        {
            return (head_index == tail_index);
        }

        // Returns whether the ring buffer is full.
        bool IsFull()
        {
            return ((head_index - tail_index) & RING_BUFFER_MASK) == RING_BUFFER_MASK;
        }

        // Returns the number of items in the ring buffer.
        RingBufferSize NumberOfItems()
        {
            return ((head_index - tail_index) & RING_BUFFER_MASK);
        }

    private:
        char buffer[RING_BUFFER_SIZE];
        volatile RingBufferSize tail_index;
        volatile RingBufferSize head_index;
};

#endif /* RINGBUFFER_H */
