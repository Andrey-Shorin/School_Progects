#include <type_traits>
#ifndef ITER_TRAILS
#define ITER_TRAILS

namespace ft {
    template <class T>
    struct iterator_traits {
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };
template < class T, class Alloc > 
class vector;

template<bool ,typename TestClass = void>
struct It;

template<typename TestClass>
struct It<true,TestClass>{
    typedef TestClass test; 
};

template <class InputIterator1, class InputIterator2>
  bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
{
  while (first1!=last1)
  {
    if (first2==last2 || *first2<*first1) return false;
    else if (*first1<*first2) return true;
    ++first1; ++first2;
  }
  return (first2!=last2);
}
template <class InputIterator1, class InputIterator2>
  bool equal ( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
  while (first1!=last1) {
    if (!(*first1 == *first2))   
      return false;
    ++first1; ++first2;
  }
  return true;
}
template< class T, class Alloc >
void swap( ft::vector<T,Alloc>& lhs,ft::vector<T,Alloc>& rhs ){
    typedef typename Alloc::pointer pointer; 
    typedef typename Alloc::size_type size_type;
           pointer temp_array = lhs._array;
           size_type temp_capasyty = lhs._capasyty;
           size_type temp_last = lhs._last;


            lhs._array = rhs._array;
            lhs._capasyty = rhs._capasyty;
            lhs._last =  rhs._last;

            rhs._array = temp_array;
            rhs._capasyty = temp_capasyty;
            rhs._last = temp_last;
        }




template<typename T,T v>
struct int_const{
    static const T value = v;
} ;

template <class _Tp> 
struct _Is_integer:public int_const<bool,false> {
   
 };
 
 template<> struct _Is_integer<bool>:public int_const<bool,true>  {
   
 };
 template<> struct _Is_integer<char>:public int_const<bool,true> {
   
 };
 
 template<> struct _Is_integer<signed char>:public int_const<bool,true> {
 
 };
 
 template<> struct _Is_integer<unsigned char>:public int_const<bool,true> {
  
 };
 
 template<> struct _Is_integer<wchar_t>:public int_const<bool,true> {
   
 };
 
 template<> struct _Is_integer<short>:public int_const<bool,true> {
   
 };
 
 template<> struct _Is_integer<unsigned short>:public int_const<bool,true> {
   
 };
 
 template<> struct _Is_integer<int>:public int_const<bool,true> {
  
 };
 
 template<> struct _Is_integer<unsigned int>:public int_const<bool,true> {
  
 };
 
 template<> struct _Is_integer<long>:public int_const<bool,true> {
  
 };
 
 template<> struct _Is_integer<unsigned long>:public int_const<bool,true> {
  
 };
 
 template<> struct _Is_integer<long long>:public int_const<bool,true> {
   
 };
 
 template<> struct _Is_integer<unsigned long long>:public int_const<bool,true> {
   
 };
template<class T1,class T2>
struct pair{
  public:
  typedef T1 first_type;
  typedef T2 second_type;
  T1 first;
  T2 second;
  pair():first(T1()),second(T2()){}
  pair(const pair& other):first(other.first),second(other.second){}
  template<class U, class V>
  pair (const pair<U,V>& pr):first(pr.first),second(pr.second){}
  pair (const first_type& a, const second_type& b):first(a),second(b){}
};
template< class T1, class T2 >
pair<T1, T2> make_pair( T1 t, T2 u ){
  return pair<T1,T2>(t,u);
}
template <class _T1, class _T2>
 inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
 { 
   return __x.first == __y.first && __x.second == __y.second; 
 }
 template <class _T1, class _T2>
 inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
 { 
   return __x.first < __y.first || 
          (!(__y.first < __x.first) && __x.second < __y.second); }
 
template <class _T1, class _T2>
 inline bool operator!=(const pair<_T1, _T2>& _x, const pair<_T1, _T2>& _y)
 { 
   return ! (_x == _y) ;
 }    
  template <class _T1, class _T2>
 inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return __y < __x;
 }  
 
 template <class _T1, class _T2>
 inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return !(__y < __x);
 }
 
 template <class _T1, class _T2>
 inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
   return !(__x < __y);
 }   



}
#endif