
#include "iterator_trails.hpp"
#ifndef REVERS_ITER
#define REVERS_ITER
namespace ft{
template < class T>
class rand_iterator{
     protected:
        T* p;
    public:
        typedef  T value_type;
        typedef  ptrdiff_t difference_type;
        
        rand_iterator():p(0){}
        rand_iterator(T* pointer): p(pointer){}
        rand_iterator(const rand_iterator &other): p(other.p) {}
	    virtual ~rand_iterator() {}
        T* base()const {
            return p;
        }

	    rand_iterator &operator=(rand_iterator const &other)  {
		    this->p = other.p;
		    return (*this);
	    }

    

	    rand_iterator operator++(int) {
		    rand_iterator tmp(*this);
		    ++this->p;
		    return (tmp);
	    }
	    rand_iterator &operator++() {
		    ++this->p;
		    return (*this);
	    }
	    rand_iterator operator--(int) {
		    rand_iterator tmp(*this);
		    --this->p;
		    return (tmp);
	    }
	    rand_iterator &operator--() {
		    --this->p;
		    return (*this);
	    }

	    rand_iterator &operator+=(int value) {
		    this->p += value;
		    return (*this);
	    }
	    rand_iterator operator+(difference_type value) const {
		    rand_iterator tmp(*this);
		    return (tmp += value);
	    }
        friend rand_iterator		operator+(difference_type n, const rand_iterator &rhs) 
            { return rhs.operator+(n); };
        friend rand_iterator		operator-(difference_type n, const rand_iterator &rhs) 
            { return rhs.operator+(n); };

	    rand_iterator operator-(difference_type value) const {
		    rand_iterator tmp(*this);
		    return (tmp -= value);
	    }
	    difference_type operator-(rand_iterator const &other) const {
		    return (this->p - other.p);
	    }

	    bool operator==(rand_iterator const &other) const {
		    return (this->p == other.p);
	    }

	    

};
template < typename Iter>
class reverse_iterator{
        protected:
        Iter current;
    public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::reference reference;
        reverse_iterator(){}
        virtual ~reverse_iterator(){}
        explicit reverse_iterator(iterator_type x ){
            current = x;
        }
        template <class U>
        reverse_iterator(const reverse_iterator<U> &u):current(Iter(u.base())){
            
        }
		// template <class U> reverse_iterator &operator=(const reverse_iterator<U> &u){

        // }
        // template< class U >
        // reverse_iterator(reverse_iterator<U>& other ){
        //     current = other;
        // }
        iterator_type base() const{
            return (current);
        }
        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other ){
            current = other.base();
            return *this;
        }
   
        pointer operator->() const{
            return &(operator*());
        }
        reference operator*(){
            Iter tmp = this->current;
            return *(--tmp);
        }
        const reference operator*() const{
            Iter tmp = this->current;
            return *(--tmp);
        }
 
        reverse_iterator& operator++(){
            current--;
            return *this;
        }
        reverse_iterator& operator--(){
            current++;
            return *this;
        }     
  
        reverse_iterator operator++( int ){
            reverse_iterator temp(current);
            --current;
            return temp;
        }
        reverse_iterator operator--( int ){
            reverse_iterator temp(current);
            current++;
            return temp;
        }
        reverse_iterator operator+( difference_type n ) {
            return reverse_iterator(base()-n);
        }
        reverse_iterator operator-( difference_type n ) {
            return reverse_iterator(base()+n);
        }
        reverse_iterator& operator+=( difference_type n ) {
            this->current.operator-=(n);
            return *this;
        }
        reverse_iterator& operator-=( difference_type n ){
            this->current.operator+=(n);
            return *this;
        }

     
        reference operator[]( difference_type n ) {
            return this->base()[-n-1];
        }
        template <class U>
		difference_type		operator-(const reverse_iterator<U> &u) { return u.base().operator-(this->current); };


    friend reverse_iterator		operator+(difference_type n,  reverse_iterator &rhs) 
    { return rhs.operator+(n); };
    friend reverse_iterator		operator-(difference_type n,  reverse_iterator &rhs) 
    { return rhs.operator+(n); };
// template<typename _IteratorL>
// bool operator-(const reverse_iterator<_IteratorL>& __lhs)
//      { return __lhs.base() - this->base() ; }
 	

	template<typename _IteratorL, typename _IteratorR>
friend inline bool
 operator!=(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs)
     { return __lhs.base() != __rhs.base() ; }
 	
     template<typename _IteratorL, typename _IteratorR>
friend inline bool
 operator==(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs){
            return __lhs.base() == __rhs.base() ;
        }
 
     template<typename _IteratorL, typename _IteratorR>
friend inline bool
 operator<(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs)
    {return __lhs.base() > __rhs.base() ;}
 	
        template<typename _IteratorL, typename _IteratorR>
 friend inline bool
 operator<=(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs){
        return (__lhs.base() >= __rhs.base());}


    template<typename _IteratorL, typename _IteratorR>
 friend inline bool
 operator>(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs) {
		return (__lhs.base() < __rhs.base());
	}

    template<typename _IteratorL, typename _IteratorR>
 friend inline bool
 operator>=(const reverse_iterator<_IteratorL>& __lhs,
        const reverse_iterator<_IteratorR>& __rhs) {
		return (__lhs.base() <= __rhs.base());
	}

};

template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator!=(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs)
                    { return __lhs.base() != __rhs.base() ; }

        template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator==(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs)
                    { return __lhs.base() == __rhs.base() ; } 
        template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator<(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs)
                    {return __lhs.base() < __rhs.base() ;}	
        template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator<=(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs) 
                    {return (__lhs.base() <= __rhs.base());}


        template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator>(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs)
                    {return (__lhs.base() > __rhs.base());}

        template<typename _IteratorL, typename _IteratorR>
         inline bool
            operator>=(const rand_iterator<_IteratorL>& __lhs,
                const rand_iterator<_IteratorR>& __rhs)
                    {return (__lhs.base() >= __rhs.base());}

}
#endif