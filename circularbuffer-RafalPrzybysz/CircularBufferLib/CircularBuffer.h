#pragma once
#include <array>

template <typename T, size_t const maxSize>
class CircularBuffer
{
private:
    std::array<T, maxSize> buffer{};
    size_t firstToRead;
    size_t firstFree;
    bool empty;

public:
    CircularBuffer() noexcept : firstToRead(0), firstFree(0), empty(true)
    {
    }

    size_t size() const noexcept
    {
        if (firstToRead == firstFree && !empty)
            return maxSize;
        else
            return (firstFree + maxSize - firstToRead) % maxSize;
    }

    bool push(T const v) noexcept
    {
        if (!empty && firstToRead == firstFree)
            return false;
        else
        {
            buffer[firstFree] = v;
            firstFree = (firstFree + 1) % maxSize;
            empty = false;
            return true;
        }
    }

	bool pop(T& v) noexcept
	{
		//TODO zaimplementowaæ metodê pop odczytuj¹c¹ (i usuwaj¹c¹) wartoœæ z bufora cyklicznego
		
		if (empty)
			return false;
		else
		{
			v = buffer[firstToRead];
			firstToRead = (firstToRead + 1) % maxSize;

			if(firstToRead == firstFree)
			empty = true;

			return true;
		}
		

	}
};