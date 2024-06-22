#ifndef FT_STACK
#define FT_STACK

#include "vector.hpp"


namespace ft{
template <class A, class Container = vector<A> > 
    class stack{
    protected:
        Container  c;
    public:
        typedef A value_type;
        typedef Container container_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;
        explicit stack (const container_type& ctnr = container_type()){
            c = ctnr;
        }
        ~stack(){}
        stack& operator=( const stack& other ){
            c = other.c;
            return *this;
        }
        value_type& top(){
            return c.back();
        }
        value_type& top() const{
            return c.back();
        }
        bool empty() const{
            return  c.empty();
        }
        size_type size() const{
            return c.size();
        }
        void push (const value_type& val){
            c.push_back(val);
        }
        void pop(){
            c.pop_back();
        }

        template< class T, class Container2 >
        friend bool operator==( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );
        
        template< class T, class Container2 >
        friend bool operator!=( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );
	
        template< class T, class Container2 >
        friend bool operator<( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );

        template< class T, class Container2 >
        friend bool operator<=( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );

        template< class T, class Container2 >
        friend bool operator>( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );

        template< class T, class Container2 >
        friend bool operator>=( const stack<T,Container2>& lhs, const stack<T,Container2>& rhs );  

};
template< class T, class Container >
    bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
    return (lhs.c == rhs.c);
    }
template< class T, class Container >
    bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
        return (lhs.c != rhs.c);
    }
template< class T, class Container >
    bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
        return (lhs.c < rhs.c);
    }
template< class T, class Container >
    bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
        return (lhs.c <= rhs.c);
    }	
template< class T, class Container >
    bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
        return (lhs.c > rhs.c);
    }	
template< class T, class Container >
    bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ){
        return (lhs.c >= rhs.c);
    }
}
#endif