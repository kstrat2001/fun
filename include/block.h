#pragma once

#include "icomparable.h"

namespace gfx
{
    class Block : public IComparable
    {
        public:
            Block( unsigned int size );
            virtual ~Block();

            virtual int GetValue() const;

        private:
            unsigned int mSize;
    };
}
