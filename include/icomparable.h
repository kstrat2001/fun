#pragma once


namespace gfx
{
    class IComparable
    {
    public:
        virtual ~IComparable() {};

        virtual int GetValue() const = 0;

        virtual int Compare( const IComparable& rhs ) const
        {
            return (this->GetValue() - rhs.GetValue());
        }
    };
}
