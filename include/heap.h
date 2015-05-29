#pragma once


namespace gfx
{
    class Heap
    {
    public:
        Heap();
        ~Heap();

        void* AllocateBlock(unsigned int size);

    private:
        Heap(const Heap& heap);
        Heap& operator=(const Heap& rhs);
    };
}
