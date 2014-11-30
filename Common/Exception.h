// ****************************************************************************
// Hush
//
// AUTHOR:  Justin Shen
//
// NOTES: 
//      Defines the basic exception types
//
// ****************************************************************************

#ifndef HUSH_EXCEPTION_H
#define HUSH_EXCEPTION_H

#include "BasicType.h"
#include "String.h"

namespace Hush
{
	class Exception
	{
	protected:
		String message;
	public:
		Exception(String message)
			:message(message)
		{
		}

		const String& GetMessage() const
		{
			return message;
		}
	};
}

#endif