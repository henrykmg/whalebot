#pragma once

#include <vector>

namespace korm {
	
//map old plain data types
template<class T>
class CMapper {
public:
	CMapper( const T& opd )
	: m_pPtr((const char*)(&opd))
	{}
	
	const char* dataPointer() const
	{
		return m_pPtr;
	}
	
	size_t dataSize() const
	{
		return sizeof(T);
	}
	
private:
	const char*	m_pPtr;
};

//unmap old plain data types
template<class T>
class CUnMapper {
public:
	CUnMapper( T& target )
	: m_tData(target)
	{}
	
	void unMap( const char *dataPtr, size_t dataSize )
	{
		memcpy(&m_tData, dataPtr, dataSize);
	}
	
	
private:
	T&  m_tData;
};

template<class T>
class CMapper<std::vector<T> > {
public:
    typedef std::vector<T>  CVector;
    
	CMapper( const CVector& vpd )
	: m_pPtr((const char*)(&vpd[0]))
    , m_iSize(sizeof(T) * vpd.size())
	{}
	
	const char* dataPointer() const
	{
		return m_pPtr;
	}
	
	size_t dataSize() const
	{
		return m_iSize;
	}
	
private:
	const char*	m_pPtr;
    size_t          m_iSize;
};

template<class T>
class CUnMapper<std::vector<T> > {
public:

    typedef std::vector<T>  CVector;
    
	CUnMapper( CVector& target )
	: m_vData(target)
	{}
	
	void unMap( const char *dataPtr, size_t dataSize )
	{
        m_vData.resize(dataSize / sizeof(T));        
		memcpy(&m_vData[0], dataPtr, dataSize);
	}
	
	
private:
	CVector&				m_vData;
};

template<class T>
class CTraits {
public:
	typedef CMapper<T>		CDefaultMapper;
	typedef CUnMapper<T>	CDefaultUnMapper;
};

}//korm - kyoto orm
