// Adapted from https://github.com/AndersKaloer/Ring-Buffer/

#include "ringbuffer.h"

void RingBuffer::Reset()
{
    tail_index = 0;
    head_index = 0;
}

void RingBuffer::Queue(char data)
{
    if (IsFull())
    {
        // Is going to overwrite the oldest byte
        // Increase tail index
        tail_index = ((tail_index + 1) & RING_BUFFER_MASK);
    }

    /// Place data in buffer
    buffer[head_index] = data;
    head_index = ((head_index + 1) & RING_BUFFER_MASK);
}

void RingBuffer::Queue(const char* data, RingBufferSize size)
{
    // Add bytes; one by one
    RingBufferSize i;
    for (i = 0; i < size; i++)
    {
        RingBuffer::Queue(buffer, data[i]);
    }
}

bool RingBuffer::Dequeue(char* data)
{
    if (IsEmpty())
    {
        return false;
    }

    *data = buffer[tail_index];
    tail_index = ((tail_index + 1) & RING_BUFFER_MASK);
    return true;
}

RingBufferSize RingBuffer::Dequeue(char* data, RingBufferSize size)
{
    if (IsEmpty())
    {
        return false;
    }

    char* data_ptr = data;
    RingBufferSize count = 0;
    while((count < size) && Dequeue(data_ptr))
    {
        count++;
        data_ptr++;
    }
    return count;
}

bool RingBuffer::Peek(char* data, RingBufferSize index)
{
    if (index >= NumberOfItems())
    {
        return false;
    }

    // Add index to pointer
    RingBufferSize data_index = ((tail_index + index) & RING_BUFFER_MASK);
    *data = buffer[data_index];
    return true;
}
