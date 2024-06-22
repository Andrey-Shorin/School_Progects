#include <memory>
#include <cstddef>
#include <limits> 

#include <iostream>
#include "reverse_iterator.hpp"
#include "iterator_trails.hpp"
#ifndef FT_VECTOR
#define FT_VECTOR
namespace ft {
template < class T>
T min(T a, T b){
    if (a < b)
        return a;
    return b;
}

template < class T>
class iterator_vector: public rand_iterator<T>{

    public:
        typedef  T value_type;
        typedef  std::random_access_iterator_tag iterator_category;
        typedef  ptrdiff_t difference_type;
        typedef  T* pointer;
        typedef T& reference;
        iterator_vector():rand_iterator<T>(0){}
        iterator_vector(T* pointer): rand_iterator<T>(pointer){}
        iterator_vector(const iterator_vector &other): rand_iterator<T>(other.p) {}
        // template<typename U>
    //    iterator_vector(iterator_vector<U> &other): p((T*) other.base()) {}
	    virtual ~iterator_vector() {}
    // operator iterator_vector<const T>(){return  iterator_vector<const T>(p);}
    // operator const_iterator_vector<T>(){return  const_iterator_vector<T>(p);}
	iterator_vector &operator=(iterator_vector const &other) {
		this->p = other.p;
		return (*this);
	}
        pointer base()const {
            return this->p;
        }
	    pointer operator->() {
		    return (this->p);
	    }


    

	iterator_vector operator++(int) {
		iterator_vector tmp(*this);
		++this->p;
		return (tmp);
	}
	iterator_vector &operator++() {
		++this->p;
		return (*this);
	}
	iterator_vector operator--(int) {
		iterator_vector tmp(*this);
		--this->p;
		return (tmp);
	}
	iterator_vector &operator--() {
		--this->p;
		return (*this);
	}

	iterator_vector &operator+=(int value) {
		this->p += value;
		return (*this);
	}
	iterator_vector operator+(difference_type value) const {
		iterator_vector tmp(*this);
		return (tmp += value);
	}
friend iterator_vector		operator+(difference_type n, const iterator_vector &rhs) 
{ return rhs.operator+(n); };
friend iterator_vector		operator-(difference_type n, const iterator_vector &rhs) 
{ return rhs.operator+(n); };



	iterator_vector &operator-=(difference_type value) {
		this->p -= value;
		return (*this);
	}
	iterator_vector operator-(difference_type value) const {
		iterator_vector tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(rand_iterator<T> const &other) const {
		return (this->p - other.base());
	}

	T& operator*() const{
		return (*this->p);
	}
    T& operator[](int val) const{
		return (*(this->p + val));
	}
};
template < class T>
class const_iterator_vector: public rand_iterator<T>{

    public:
        typedef  T value_type;
        typedef  std::random_access_iterator_tag iterator_category;
        typedef  ptrdiff_t difference_type;
        typedef  const T* pointer;
        typedef const T& reference;

        const_iterator_vector():rand_iterator<T>(0){}
        const_iterator_vector(T* pointer): rand_iterator<T>(pointer){}
        const_iterator_vector(const const_iterator_vector &other): rand_iterator<T>(other.base()) {}
        const_iterator_vector(const iterator_vector<T> &other): rand_iterator<T>(other.base()) {}
        // template<typename U>
       //const_iterator_vector(const_iterator_vector<U> &other): p((T*) other.base()) {}
	    virtual ~const_iterator_vector() {}
    //operator const_iterator_vector<const T>(){return  const_iterator_vector<const T>(p);}
	const_iterator_vector &operator=(const_iterator_vector const &other) {
		this->p = other.p;
		return (*this);
	}
    T* base()const {
            return this->p;
        }


	reference operator*() const {
		return (*this->p);
	}
	pointer operator->() {
		return (this->p);
	}
    reference operator[](int val) const {
		return (*(this->p + val));
	}

	const_iterator_vector operator++(int) {
		const_iterator_vector tmp(*this);
		++this->p;
		return (tmp);
	}
	const_iterator_vector &operator++()  {
		++this->p;
		return (*this);
	}
	const_iterator_vector operator--(int)  {
		const_iterator_vector tmp(*this);
		--this->p;
		return (tmp);
	}
	const_iterator_vector &operator--()  {
		--this->p;
		return (*this);
	}

	const_iterator_vector &operator+=(int value)  {
		this->p += value;
		return (*this);
	}
	const_iterator_vector operator+(difference_type value)  {
		const_iterator_vector tmp(*this);
		return (tmp += value);
	}
friend const_iterator_vector		operator+(difference_type n, const const_iterator_vector &rhs) 
{ return rhs.operator+(n); };
friend const_iterator_vector		operator-(difference_type n, const const_iterator_vector &rhs) 
{ return rhs.operator+(n); };



	const_iterator_vector &operator-=( difference_type value ) {
		this->p -= value;
		return (*this);
	}
	const_iterator_vector operator-(difference_type value) const {
		const_iterator_vector tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(const_iterator_vector const &other) const {
		return (this->p - other.p);
	}


};

template < class T, class Alloc = std::allocator<T> > 
class vector{
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename Alloc::pointer pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef const pointer const_pointer;
        typedef iterator_vector<T> iterator;
        typedef const_iterator_vector<T> const_iterator;
        typedef size_t size_type;
        typedef ptrdiff_t   difference_type;
        typedef reverse_iterator<const_iterator> const_reverse_iterator;
        typedef reverse_iterator<iterator> reverse_iterator;
        
    private:
        allocator_type _alloc;
        pointer _array;
        size_type _capasyty;
        size_type _last;
    public:

    // void get_par(){
    //     std::cout << "_array = " << _array << " _capasyty = " << _capasyty << " _last = " << _last << std::endl;
    // }
    explicit vector (const allocator_type& alloc = allocator_type()):_alloc(alloc),_array(0),_capasyty(0),_last(0){}
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()){
        _alloc = alloc;
        _array = 0;
        _capasyty = 0;
        _last = 0;
        reserve(n);
        for(size_type i = 0; i != n; i++){
            _alloc.construct(_array + i,val);
            _last++; 
        }
    }
    template <class InputIterator>
    vector (typename It<!_Is_integer<InputIterator>::value, InputIterator>::test  first, InputIterator last, const allocator_type& alloc = allocator_type()){
        _alloc = alloc;
        _array = 0;
        _capasyty = 0;
        _last = 0;
        insert(begin(),first,last);
    }
    vector (const vector& x){
        _alloc = x._alloc;
        _array = 0;
        _capasyty = 0;
        _last = 0;
        insert(begin(),x.begin(),x.end());
    }
 
    vector& operator= (const vector& x){
        if(&x != this){
        clear();
        insert(begin(),x.begin(),x.end());}
        return *this;
    }

        ~vector(){
            if (this->_array == 0)
                return;
           clear();
           _alloc.deallocate(_array,_capasyty);
            _array = 0;
            _capasyty = 0;
            _last = 0;
        }

    template< class A, class B >
    friend bool operator==( const vector<A,B>& lhs,
                 const vector<A,B>& rhs ) ;
    template< class A, class B >
    friend bool operator!=( const vector<A,B>& lhs,
                 const vector<A,B>& rhs ) ;

    template< class A, class B >
    friend bool operator<( const vector<A,B>& lhs,
                const vector<A,B>& rhs ) ;

    template< class A, class B >
    friend bool operator<=( const vector<A,B>& lhs,
                 const vector<A,B>& rhs ) ;

    template< class A, class B >
    friend bool operator>( const vector<A,B>& lhs,
                const vector<A,B>& rhs ) ;

    template< class A, class B >
    friend bool operator>=( const vector<A,B>& lhs,
                 const vector<A,B>& rhs ) ;
        
        //iterators
        iterator begin(){return iterator(_array);}
        const_iterator begin()const{return const_iterator(_array);}
        iterator end(){return iterator(_array + _last);}
        const_iterator end() const{return const_iterator(_array + _last);}

        reverse_iterator rbegin(){return reverse_iterator(_array + _last);}
        const_reverse_iterator rbegin() const {return const_reverse_iterator(_array + _last);}
        reverse_iterator rend(){return reverse_iterator(_array);}
        const_reverse_iterator rend()const {return const_reverse_iterator(_array);}
        
        bool empty() const{return _last ? false : true; }
        size_type size() const{ return _last;}
        void reserve(size_type len){
            if(_capasyty < len){
                pointer new_array = _alloc.allocate(len);
                try{
                    _coppy(new_array,_last);
                }
                catch(...){
                    _alloc.deallocate(new_array,len);
                    throw;
                }
                for(size_type i = 0;i != _last; i++){
                    _alloc.destroy(_array + i);
                }
                pointer temp = _array;
                size_type temp_len = _capasyty;
                _array = new_array;
                _capasyty = len;
                if (temp)
                    _alloc.deallocate(temp,temp_len);
            }
        }
        size_type max_size(void) const {
		return (min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
	    }
        size_type capacity() const{
            return this->_capasyty;
        }
        allocator_type get_allocator() const{
            return this->_alloc;
        }
        void clear(){
            for(size_type i = 0;i != _last; i++){
                    _alloc.destroy(_array + i);
                }
            _last = 0;
        }
        void insert (iterator position, size_type n, const value_type& val){
            difference_type dist = position - begin();
            difference_type temp_last = _last;
          
            _move_right(dist,n);
   
            try{
               
                for(difference_type j = dist; j <  difference_type (dist + n); j++){
                    _alloc.construct(_array + j,val);
                    
                    _last++;
                }
                }catch(...){
                    // std::cerr << "ERRR\n";
                    _destroy(_array + dist + n,_array + temp_last + n - 1);
                    throw;
                }
                _last = temp_last + n;
        }
        iterator insert(iterator position, const value_type& val){
                difference_type dist = position - begin();
                _move_right(dist,1);
                try{

                    _alloc.construct(&(*begin()) + dist,val);
                }catch(...){
                    // std::cerr << "ERRR\n";
                    _alloc.destroy(&(*end())); 
                    throw;
                }
                 _last++;
                 return iterator(&(*begin()) + dist);
        }
        template <class InputIterator>
        void insert (iterator position, typename It<!_Is_integer<InputIterator>::value, InputIterator>::test first , InputIterator last){
            if(first == last){
                return;
            }
             difference_type dist = position - begin();
                for(size_type j = 0; first  != last; j++, first++){
                    _move_right(dist + j ,1);
                    _last++;
                    try{
                        _alloc.construct(_array + dist + j,(*first));

                    }catch(...){
                        // std::cerr << "ERRR\n";
                        _destroy(_array + dist + j + 1 ,&(*end()));
                        _last = dist + j + 1;
                        throw;
                    }

                }
        }
   
        void assign(size_type n, const_reference val){
            clear();
            reserve(n);
            for(size_type i = 0; i != n; i++){
                _alloc.construct(_array + i,val);
                _last++; 
            }
        }
             template <class InputIterator>
        void assign (InputIterator first, typename It<!_Is_integer<InputIterator>::value, InputIterator>::test last){
            clear();
            insert(begin(),first,last);
        }
        iterator erase(iterator pos ){
            for (iterator i = pos; i != end() - 1; i++){
                *(i) = *(i+1);
            }
            _alloc.destroy(&(*(end() -1)));
            _last --;
            return  pos;
        }
        iterator erase( iterator first, iterator last ){
            iterator j = last - 1;
            iterator i = first;
            for (; j < end() - 1; (i++,j++)){
                *(i) = *(j+1);
            }
            size_type k = 0;
            for (;i != end();i++){
                _alloc.destroy(&(*i));
                k++;
            }
            _last -= k;
            return first;
        }
        reference at( size_type pos){
            if(pos >= _last) {
                throw std::out_of_range("Vector index out of range");}
            return _array[pos];
        }
        const_reference at (size_type n) const{
            if(n >= _last) {
                throw std::out_of_range("Vector index out of range");}
            return _array[n];
        }
        reference front(){
             return *_array;
         }
        
        const_reference front() const{
            return *_array;
         }
        reference back(){
            return *(_array + _last -1);
        }
        const_reference back() const{
            return *(_array + _last -1);
        } 
        value_type* data(){
            return _array;
        }
        const value_type* data() const{
            return _array;
        }

        void push_back(const value_type& val){
            if (_last + 1 > _capasyty){
                _increase();
            }
            _alloc.construct(_array + _last,val);
            _last++;
        }
        const_reference operator[] (size_type n) const{
            return (*(_array + n));
        }
        reference operator[] (size_type n){
            return (*(_array + n));
        }
        void pop_back(){
            _alloc.destroy(_array + _last - 1);
            _last--;
        }   
        template< class T1, class Alloc1 >
friend void swap( vector<T1,Alloc1>& lhs, vector<T1,Alloc1>& rhs );

        void swap( vector& other ){
            pointer temp_array = other._array;
            size_type temp_capasyty = other._capasyty;
            size_type temp_last = other._last;
            
            other._array = this->_array;
            other._capasyty = this->_capasyty;
            other._last =  this->_last;

            this->_array = temp_array;
            this->_capasyty = temp_capasyty;
            this->_last = temp_last;
        }
        void resize (size_type n, value_type val = value_type()){
            if (n > _last){
                if(n > _capasyty){
                    reserve(n);}
                for (pointer i = (_array + _last); (size_type)(i -_array) != n; i++){
                    _alloc.construct(i,val); 
                    _last++;
                }
            }
            else if (n < _last)
            {
                pointer new_array = _alloc.allocate(n);
                try{
                    _coppy(new_array,n);
                }
                catch(...){
                    // std::cerr << "ERRR\n";
                    _alloc.deallocate(new_array,n);
                    throw;
                }
                for(size_type i = 0;i != _last; i++){
                    _alloc.destroy(_array + i);
                }
                pointer temp = _array;
                size_type temp_len = _capasyty;
                _array = new_array;
                _capasyty = n;
                _last = n;
                _alloc.deallocate(temp,temp_len);
            }
            
        }


        private:
        void _coppy(pointer new_array,difference_type last){
            difference_type i = 0;
            try{
                for(;i < last; i++){
                    _alloc.construct(new_array + i,_array[i]);
                }
            } catch(...){
                // std::cerr << "ERRR\n";
                for(i--;i != -1; i--){
                    _alloc.destroy(new_array + i); 
                }
                throw;
            }
        }
        void _move_right(size_type start,size_type dist){ 
            if (dist == 0)
                return;
            if (dist + _last > _capasyty){
                if (_capasyty * 2 > dist + _last){
                    reserve(_capasyty * 2);
                }
                else{
                    reserve(dist + _last);
                }
            }
            size_type j;
            if(_last == start || _last == 0){
                return;
            }
            try{
                for(j = 0; j < _last - start;j++){
                    _alloc.construct(_array + (_last - 1) + dist - j,*(_array + (_last - 1) - j));
                    _alloc.destroy(_array + (_last - 1)- j);
                }
            }catch(...){
   
                for(size_type i = j - 1 ; i + 1 != 0 ; i--){
                    _alloc.destroy(_array + _last - 1 - i);
                }
                 //std::cout << "move end err\n";
                //_destroy(_array + j + dist + 1 ,_array + _last +  dist - 1);
                throw;
            }
            //  std::cout << "move end\n";
        }
        void _destroy(pointer start, pointer end){
            pointer i = start;
            for(; i <= end;i++){
                _alloc.destroy(i);
            }
        }
        
        void _increase(){
                size_type new_capasyty;
                if (_capasyty == 0){
                    new_capasyty = 1;
                }else{
                    new_capasyty = _capasyty * 2;
                }
                reserve(new_capasyty);
        }

};
	template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator!=(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)
 { return __lhs.base() != __rhs.base() ; }

	template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator==(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)
 { return __lhs.base() == __rhs.base() ; }

     template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator<(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)
        {return __lhs.base() < __rhs.base() ;}
 	
    template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator<=(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)  {
		return (__lhs.base() <= __rhs.base());
	}


    template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator>(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)  {
		return (__lhs.base() > __rhs.base());
	}

    template<typename _IteratorL, typename _IteratorR>
 inline bool
 operator>=(const const_iterator_vector<_IteratorL>& __lhs,
        const const_iterator_vector<_IteratorR>& __rhs)  {
		return (__lhs.base() >= __rhs.base());
	}



 template< class T, class Alloc >
    bool operator==( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs )
        {
            return lhs.size() == rhs.size() && ft::equal(lhs.begin(),lhs.end(),rhs.begin());
        }

 //lllll
 
 template< class T, class Alloc >
bool operator!=( const vector<T,Alloc>& lhs,
                 const vector<T,Alloc>& rhs )
                 {return !(lhs == rhs);}

template< class T, class Alloc >
bool operator<( const vector<T,Alloc>& lhs,
                const  vector<T,Alloc>& rhs )
    {
        return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }

template< class T, class Alloc >
bool operator<=( const  vector<T,Alloc>& lhs,
                 const  vector<T,Alloc>& rhs )
    {
        return (lhs < rhs || lhs == rhs);
    }

template< class T, class Alloc >
bool operator>( const  vector<T,Alloc>& lhs,
                const  vector<T,Alloc>& rhs )
    {
        return ft::lexicographical_compare(rhs.begin(),rhs.end(),lhs.begin(),lhs.end());
    }
template< class T, class Alloc >
bool operator>=( const  vector<T,Alloc>& lhs,
                 const  vector<T,Alloc>& rhs )
    {
        return (lhs > rhs || lhs == rhs);
    }
}
#endif