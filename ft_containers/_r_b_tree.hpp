#ifndef RB_TREE
#define RB_TREE

#include <memory>
//#include <cstddef>
// #include <limits> 


#include "reverse_iterator.hpp"
#include "iterator_trails.hpp"
namespace ft{
typedef bool _Rb_tree_Color_type;
const _Rb_tree_Color_type RED = false;
const _Rb_tree_Color_type BLACK = true;

template<typename _Value>
struct _rb_node{
    typedef _Rb_tree_Color_type _Color_type;
    typedef _rb_node<_Value>* _Link_type;
    typedef _rb_node* _Base_ptr;
    
    _Base_ptr _M_parent;
    _Base_ptr _M_left;
    _Base_ptr _M_right;
    _Value _M_value_field;
    _Color_type _M_color;
    _Value& get_val(){
        return _M_value_field;
    }
 

};
template <typename _Value, typename _Ref, typename _Ptr>
class _rb_iterator{
    public:
    typedef _Value value_type;
    typedef _Ref reference;
    typedef _Ptr pointer;
    typedef _rb_iterator<_Value, _Value&, _Value*>  iterator;
    typedef _rb_iterator<_Value, const _Value&, const _Value*> const_iterator;
    typedef _rb_iterator<_Value, _Ref, _Ptr>  _Self;
    typedef _rb_node<_Value>* _Link_type;
    
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef _rb_node<_Value>*  _Base_ptr;
    
    public:
   
    _Base_ptr _M_node;
    _Link_type base(){
        return _M_node;
    }
    
    _rb_iterator() {}
    _rb_iterator(_Link_type __x) { _M_node = __x; }
    // template <typename a, typename b, typename c>
    // _rb_iterator( const  _rb_iterator< a,  b,  c>& __it) { _M_node = __it._M_node; } //
   // _rb_iterator(const _rb_iterator<_Value,_Value&,_Value*>& __it){ _M_node = __it._M_node; } 
    
    
    _rb_iterator(const  iterator& __it) { _M_node = __it._M_node; }    //
   
   
   
   
    _Ref operator*() const { return (_M_node)->_M_value_field; }
    // _Self& operator=(const iterator other){
    //     _M_node = other._M_node;
    //     return *this;
    // }
    //   operator _rb_iterator<_Value, const _Ref, const _Ptr>(void) const {
	// 		return _rb_iterator<_Value, const _Ref, const _Ptr>(this->_M_node);
	// 	}
    _Ptr operator->() const { return &(operator*()); }
   void _M_increment()
   {

        if (_M_node->_M_right != 0) {
            _M_node = _M_node->_M_right;
            while (_M_node->_M_left != 0)
                _M_node = _M_node->_M_left;
        }
        else {
            _Base_ptr __y = _M_node->_M_parent;
            while (_M_node == __y->_M_right) {
                _M_node = __y;
                __y = __y->_M_parent;
            }
            if (_M_node->_M_right != __y)
                _M_node = __y;
          
        }
   }

 
void _M_decrement()
   {
     if (_M_node->_M_color == RED &&
         _M_node->_M_parent->_M_parent == _M_node)
       _M_node = _M_node->_M_right;
     else if (_M_node->_M_left != 0) {
       _Base_ptr __y = _M_node->_M_left;
       while (__y->_M_right != 0)
         __y = __y->_M_right;
       _M_node = __y;
     }
     else {
       _Base_ptr __y = _M_node->_M_parent;
       while (_M_node == __y->_M_left) {
         _M_node = __y;
         __y = __y->_M_parent;
       }
       _M_node = __y;
     }
   }
 
      _Self& operator++() { _M_increment(); return *this; }
   _Self operator++(int) {
     _Self __tmp = *this;
     _M_increment();
     return __tmp;
   }
   _Self& operator--() { _M_decrement(); return *this; }
   _Self operator--(int) {
     _Self __tmp = *this;
     _M_decrement();
     return __tmp;
   }

	_Self &operator+=(difference_type value)  {
        while(value != 0){
             _M_increment();
             value--;
        }
		return (*this);
	}
	_Self operator+(difference_type value)  {
		_Self tmp(*this);
		return (tmp += value);
	}
friend _Self		operator+(difference_type n, const _Self &rhs) 
{ _Self tmp(rhs);
		return (tmp += n); };
friend _Self		operator-(difference_type n, const _Self &rhs) 
{ _Self tmp(rhs);
		return (tmp -= n); };



	_Self &operator-=( difference_type value ) {
		while(value != 0){
             _M_decrement();
             value--;
        }
		return (*this);
	}
	const_iterator operator-(difference_type value) const {
		const_iterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(const_iterator const &other) const {
        difference_type i = 0;
		while (other != *this){
            other++;
            i++;
        }
        return i;
	}


};

template <class _Value, class _Ref, class _Ptr>
 inline bool operator==(const _rb_iterator<_Value, _Ref, _Ptr>& __x,
                const _rb_iterator<_Value, _Ref, _Ptr>& __y) {
   return __x._M_node == __y._M_node;
 }
 
 template <class _Value>
 inline bool operator==(const _rb_iterator<_Value, const _Value&, const _Value*>& __x,
                const _rb_iterator<_Value, _Value&, _Value*>& __y) {
   return __x._M_node == __y._M_node;
 }
 
 template <class _Value>
 inline bool operator==(const _rb_iterator<_Value, _Value&, _Value*>& __x,
                const _rb_iterator<_Value, const _Value&, const _Value*>& __y) {
   return __x._M_node == __y._M_node;
 }
 
 template <class _Value, class _Ref, class _Ptr>
 inline bool operator!=(const _rb_iterator<_Value, _Ref, _Ptr>& __x,
                const _rb_iterator<_Value, _Ref, _Ptr>& __y) {
   return __x._M_node != __y._M_node;
 }
 
 template <class _Value>
 inline bool operator!=(const _rb_iterator<_Value, const _Value&, const _Value*>& __x,
                const _rb_iterator<_Value, _Value&, _Value*>& __y) {
   return __x._M_node != __y._M_node;
 }
 
 template <class _Value>
 inline bool operator!=(const _rb_iterator<_Value, _Value&, _Value*>& __x,
                const _rb_iterator<_Value, const _Value&, const _Value*>& __y) {
   return __x._M_node != __y._M_node;
 }


template<typename _Tp,typename _KEY, typename _Compare1, typename _Alloc_base>
class _rb_tree{
    public:
    size_t amount;
    _Compare1 _Compare;
    typedef   _rb_tree <_Tp,_KEY, _Compare1 , _Alloc_base> tree;
    typedef  typename _Alloc_base::template rebind<_rb_node<_Tp> >::other _Alloc_type;
    _Alloc_type _Alloc;
    _Alloc_base _Alloc_b;
    _rb_node<_Tp>* _M_header;
    public:
    typedef _Tp value_type;
    typedef ptrdiff_t difference_type;
    typedef _rb_node<_Tp>* _link;
    typedef _rb_node<_Tp> _node;
    typedef size_t size_type;
    typedef _rb_iterator<_Tp,_Tp&,_Tp*> iterator;
    typedef  _rb_iterator<_Tp, const _Tp&,  const  _Tp* > const_iterator;
    typedef  reverse_iterator< const_iterator>  const_reverse_iterator;
    typedef  reverse_iterator<iterator> reverse_iterator;
    
    typedef pair<iterator,bool> ret_pair;
    void swap (tree& x){
        _link tepp =_M_header;
        size_t am = amount;
        _M_header = x._M_header;
        amount = x.amount;
        x._M_header = tepp;
        x.amount = am;

    }
   _Compare1 key_comp() const{
       return _Compare;
   }
    _Alloc_base get_allocator() const{
        return _Alloc_b;
    }
    void clear(){
        while (amount != 0)
            erase(begin());
        _M_header->_M_left = 0;
    }
    iterator begin(){
        _link h = _M_header;
         while (h->_M_left != 0){
          
                h = h->_M_left;
         }
        return iterator(h);
    }
    const_iterator begin() const{
        _link h = _M_header;
         while (h->_M_left != 0){
          
                h = h->_M_left;
         }
        return const_iterator(h);
    }
    iterator end(){
        return iterator(_M_header);
    }
    const_iterator end() const{
        return const_iterator(_M_header);
    }
   
    bool operator==(const _rb_tree& other )const{
        const_iterator a(other.begin());
        const_iterator b = begin();
        while(a != other.end() && b != end() && *b == *a){
            a++;
            b++;
        }
        return a == other.end() && b == end();
    
    }

    size_type count( const _KEY& key ) const{
        _link _x,_y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(key,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),key)){
                            
                            return 1;
                        }
                        _y = _y->_M_right;
                    }
                } 
                return 0;

    }
    template<class KEY>
    _Tp* find( const KEY& key ) const{
        _link _x,_y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(key,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),key)){
                            
                            return (&(_y->_M_value_field));
                        }
                        _y = _y->_M_right;
                    }
                } 
                return 0;

    }
    _rb_node<_Tp>* _M_get_node()
            { return _Alloc.allocate(1); }
        
        void _M_put_node(_rb_node<_Tp>* __p)
            { _Alloc.deallocate(__p, 1); }
        
        _rb_tree(const _Compare1& com,const _Alloc_base alloc):amount(0),_Compare(com),_Alloc(alloc),_M_header(_M_get_node()){ empty_init();}
        ~_rb_tree() { clear(); _M_put_node(_M_header); }
        
        _link _create_node(const value_type  & T){
            _link temp =  _M_get_node();
            try{
                _Alloc_b.construct(&(temp->get_val()),T);
                temp->_M_left = 0;
                temp->_M_right = 0;
                temp->_M_parent = 0;
                temp->_M_color = RED;
            }catch(...){
                _M_put_node(temp);
                throw;
            }
            return temp;
        }

        void destroy_node(_link it){       
            _Alloc_b.destroy(&(it->_M_value_field));
            _M_put_node(it);
        }

        iterator lower_bound (const _KEY& _val) const{
                _link _x = _M_header ,_y = _M_header->_M_left;
                while (_y != 0){
                
                    if(!_Compare(_y->get_val(),_val)){
                        _x = _y;
                        _y = _y->_M_left;}
                    else{
                        _y = _y->_M_right;
                    }
                }
                return iterator(_x);

        }

        iterator upper_bound (const _KEY& _val) const{
                _link _x = _M_header ,_y = _M_header->_M_left;
                while (_y != 0){
                
                    if(_Compare(_val,_y->get_val())){
                        _x = _y;
                        _y = _y->_M_left;}
                    else{
                        _y = _y->_M_right;
                    }
                }
                return iterator(_x);
        }

        pair<iterator,iterator> equal_range (const _KEY& _val){           
            return pair<iterator,iterator>(lower_bound(_val),upper_bound(_val));     
        }

        pair<const_iterator,const_iterator> equal_range (const _KEY& _val) const{           
            return pair<iterator,iterator>(lower_bound(_val),upper_bound(_val));     
        }
        private:
            void empty_init(){
                _M_header->_M_color= BLACK;
                _M_header->_M_parent = 0;
                _M_header->_M_left = 0;
                _M_header->_M_right = 0;
            }
            _link uncle(_link it){
                if (it->_M_parent->_M_parent->_M_left == it->_M_parent)
                    return it->_M_parent->_M_parent->_M_right;
                return it->_M_parent->_M_parent->_M_left;
            }
 
void rotate_left(_link n)
{
    _link pivot = n->_M_right;
	
    pivot->_M_parent = n->_M_parent; 
    
        if (n->_M_parent->_M_left==n)
            n->_M_parent->_M_left = pivot;
        else
            n->_M_parent->_M_right = pivot;
    
	
    n->_M_right = pivot->_M_left;
    if (pivot->_M_left != NULL)
        pivot->_M_left->_M_parent = n;

    n->_M_parent = pivot;
    pivot->_M_left = n;
}

void
rotate_right(_link n)
{
    _link pivot = n->_M_left;
	
    pivot->_M_parent = n->_M_parent; 

        if (n->_M_parent->_M_left==n)
            n->_M_parent->_M_left = pivot;
        else
            n->_M_parent->_M_right = pivot;
    	
	
    n->_M_left = pivot->_M_right;
    if (pivot->_M_right != NULL)
        pivot->_M_right->_M_parent = n;

    n->_M_parent = pivot;
    pivot->_M_right = n;
}
public:
// int chec_tree(int i,_link x){
//     if (x == 0){
//         return i ;
//     }
//     if (x->_M_color == BLACK)
//         i++;
//     int g = chec_tree(i,x->_M_left);
//     int h = chec_tree(i,x->_M_right);
//     if(h != g)
//          std::cout << "  ERROR\n" ;
//     //std::cout << g << " +";
//     if (x->_M_color == RED && x->_M_parent != 0 && x->_M_parent->_M_color == RED){
//         std::cout << " COLOR ERROR\n" ;
//     }
//     if (x->_M_right != 0 && _Compare (x->_M_right->_M_value_field , x->_M_value_field))
//         std::cout << " WWWWW ERROR\n" ;
//     if (x->_M_left != 0 && _Compare (x->_M_value_field ,x->_M_left->_M_value_field ))
//         std::cout << " WWWWW ERROR\n" ;
//     if (!(x->_M_parent->_M_left == x || x->_M_parent->_M_right == x ))
//         std::cout << " WWWWW ERROR\n" ;
//     return g;
// }

 void insertFixup(_link x) {

   if (x == _M_header->_M_left){
        x->_M_color = BLACK;
        return ;
   }
    while (x->_M_parent->_M_color == RED) {
        if (x->_M_parent == x->_M_parent->_M_parent->_M_left) {
            if (uncle(x) != 0 && uncle(x)->_M_color ==  RED){
                x->_M_parent->_M_color = BLACK;
                uncle(x)->_M_color = BLACK;
                x->_M_parent->_M_parent->_M_color = RED;
                x = x->_M_parent->_M_parent;

            }else{
                if(x == x->_M_parent->_M_right){
                    x = x->_M_parent;
                    rotate_left(x);
                }
                x->_M_parent->_M_color = BLACK;
                x->_M_parent->_M_parent->_M_color = RED;
                rotate_right(x->_M_parent->_M_parent);
            }
        } else {

            if (uncle(x) != 0 && uncle(x)->_M_color ==  RED){
                x->_M_parent->_M_color = BLACK;
                uncle(x)->_M_color = BLACK;
                x->_M_parent->_M_parent->_M_color = RED;
                x = x->_M_parent->_M_parent;

            }else{
                if(x == x->_M_parent->_M_left){
                    x = x->_M_parent;
                    rotate_right(x);
                }
                x->_M_parent->_M_color = BLACK;
                x->_M_parent->_M_parent->_M_color = RED;
                rotate_left(x->_M_parent->_M_parent);
            }
        }
    }
    _M_header->_M_left->_M_color = BLACK;
}

            iterator _insert(_link _x,const value_type &_val){
                _link temp = _create_node(_val);
                temp->_M_parent = _x;
                if (_x == _M_header){
                    _M_header->_M_left = temp;
                    temp->_M_color = BLACK;
                    return iterator(temp);
                }
                if (_Compare(_val,_x->get_val())){
        
                    _x->_M_left = temp;
                }
                else{
                     _x->_M_right = temp;
                }  
                temp->_M_color = RED;
                 insertFixup(temp);
                 //chec_tree(0, _M_header->_M_left);
                return iterator(temp);

            }
        public:
        size_type size() const{
            return amount;
        }
        bool empty() const{
            return (! amount);
        }
        size_type max_size() const{
            return  _Alloc_b.max_size(); ;
        }
            ret_pair insert(const value_type &_val){
                //chec_tree(0, _M_header->_M_left);
                _link _x = 0;

                if (_M_header->_M_left == 0){
                    amount++;
                    return ret_pair(_insert(_M_header,_val),true);
                }
                _link _y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(_val,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),_val)){
                            return ret_pair(iterator(_y),false);
                        }
                        _y = _y->_M_right;
                    }
                    
                }
                amount++;
                return ret_pair(_insert(_x,_val),true);
            }
       
        _link & to_it(_link a){
            if (a->_M_parent->_M_left == a )
                return (a->_M_parent->_M_left);
            return (a->_M_parent->_M_right);
        }
void transplant(_link u, _link v){
    if (u->_M_parent == _M_header)
        _M_header->_M_left = v;
    else if (u->_M_parent->_M_left == u)
        u->_M_parent->_M_left = v;
    else
        u->_M_parent->_M_right = v;
    if (v != 0)
        v->_M_parent= u->_M_parent;
    
}
_link tree_min(_link x){
    
    while (x != 0 && x->_M_left != 0 )
        x = x->_M_left;
    return x;
}

iterator find_iter (const _KEY& _val) {
_link _x, _y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(_val,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),_val)){
                            return iterator(_y);
                        }
                        _y = _y->_M_right;
                    }
                    
                }
        return end();
}

const_iterator find_iter (const _KEY& _val) const{
_link _x, _y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(_val,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),_val)){
                            return iterator(_y);
                        }
                        _y = _y->_M_right;
                    }
                    
                }
        return end();
}

size_type erase( const _KEY& _val ){
    _link _x, _y = _M_header->_M_left;
                while (_y != 0){
                    _x = _y;
                    if(_Compare(_val,_y->get_val()))
    
                        _y = _y->_M_left;
                    else{
                        if(!_Compare(_y->get_val(),_val)){
                            erase(iterator(_y));
                            return 1;
                        }
                        _y = _y->_M_right;
                    }
                    
                }
        return 0;
}
    void  erase( const_iterator j ){

    _link z = j.base();
    _link x, y = z;
    _link base = y;
    bool orig_color = y->_M_color;
    bool left = true;
    if (z->_M_left == 0){
        x =  z->_M_right;
        if (z->_M_parent->_M_left == z)
            left = true;
        else
            left = false;
        transplant(z,z->_M_right);
        base = z->_M_parent;
    }else if (z->_M_right == 0){
        x = z->_M_left;
        if (z->_M_parent->_M_left == z)
            left = true;
        else
            left = false;
        transplant(z,z->_M_left);
        base = z->_M_parent;
    }else{
        y = tree_min(z->_M_right);
        orig_color = y->_M_color;
        x = y->_M_right;
        left = false;
        if (y->_M_parent == z){
            if (x != 0)
                x->_M_parent = y;
            else 
                base = y;
        }else{
            base = y->_M_parent;
            left = true;
            transplant(y,y->_M_right);
            y->_M_right = z->_M_right;
           // if (y->_M_righ != 0)
            y->_M_right->_M_parent = y;
        }
        transplant(z,y);
        y->_M_left = z->_M_left;
        if (y->_M_left != 0)
            y->_M_left->_M_parent = y;
        y->_M_color = z->_M_color;
    }
    
    if (orig_color == BLACK){
    
        deleteBalance(x,left,base);}
        //nnn();
    amount--;
    destroy_node(z);
  //  chec_tree(0, _M_header->_M_left);
	
}

void deleteBalance(_link x, bool left,_link par){
    bool init = true;
    _link w;
	while (x  != _M_header->_M_left && (x == 0 || x->_M_color == BLACK)){
        if ((init == true && left) || (x != 0 &&  x == x->_M_parent->_M_left )){
            if ( x == 0 )
                w = par->_M_right;
            else
                w = x->_M_parent->_M_right;
            if (w != 0 && w->_M_color == RED){
                w->_M_color = BLACK;
                if (x == 0){
                    par->_M_color = RED;
                    rotate_left(par);
                    w = par->_M_right;}
                else{
                    x->_M_parent->_M_color = RED;
                    rotate_left(x->_M_parent);
                    w = x->_M_parent->_M_right;}
            }
            if (((w->_M_left == 0 || w->_M_left->_M_color == BLACK) && (w->_M_right == 0 ||w->_M_right->_M_color == BLACK))){
                
                w->_M_color = RED;
                if (x == 0){ x = par; init = false;}
                else {x = x->_M_parent;}
            }else {
                if ( w->_M_right == 0 || w->_M_right->_M_color == BLACK){
                    w->_M_left->_M_color = BLACK;
                    w->_M_color = RED;
                    rotate_right(w);
                    if (x != 0)
                        w = x->_M_parent->_M_right;
                    else
                        w = par->_M_right;
                }
                if (x != 0){
                    w->_M_color = x->_M_parent->_M_color;
                    x->_M_parent->_M_color = BLACK;
                    if (w->_M_right != 0)
                        w->_M_right->_M_color = BLACK;
                    rotate_left(x->_M_parent);}
                else{
                    w->_M_color = par->_M_color;
                    par->_M_color = BLACK;
                    if (w->_M_right != 0)
                        w->_M_right->_M_color = BLACK;
                    rotate_left(par);}
                x = _M_header->_M_left;

            }
        }else {
            if ((init == true && ! left) || (x != 0 &&  x == x->_M_parent->_M_right )){
            if ( x == 0 )
                w = par->_M_left;
            else
                w = x->_M_parent->_M_left;
            if (w != 0 && w->_M_color == RED){
                w->_M_color = BLACK;
                if (x == 0){
                    par->_M_color = RED;
                    rotate_right(par);
                    w = par->_M_left;}
                else{
                    x->_M_parent->_M_color = RED;
                    rotate_right(x->_M_parent);
                    w = x->_M_parent->_M_left;}
            }
            if (((w->_M_right == 0 || w->_M_right->_M_color == BLACK) && (w->_M_left == 0 ||w->_M_left->_M_color == BLACK))){
                if (w != 0)
                    w->_M_color = RED;
                if (x == 0){ x = par; init = false;}
                else {x = x->_M_parent;}
            }else {
                if ( w->_M_left == 0 || w->_M_left->_M_color == BLACK){
                    w->_M_right->_M_color = BLACK;
                    w->_M_color = RED;
                    rotate_left(w);
                    if (x != 0)
                        w = x->_M_parent->_M_left;
                    else
                        w = par->_M_left;
                }
                if (x != 0){
                    w->_M_color = x->_M_parent->_M_color;
                    x->_M_parent->_M_color = BLACK;
                    if (w->_M_left != 0)
                        w->_M_left->_M_color = BLACK;
                    rotate_right(x->_M_parent);}
                else{
                    w->_M_color = par->_M_color;
                    par->_M_color = BLACK;
                    if (w->_M_left != 0)
                        w->_M_left->_M_color = BLACK;
                    rotate_right(par);}
                x = _M_header->_M_left;

            }
        }
    }
    }
    if (x != 0)
        x->_M_color = BLACK;
	
}


    // void nnn(){
    //     _link it = _M_header->_M_left;
    //     char h = 0;
 
    //     while (h != 'q'){
    //         std::cout<< " val =" << it->_M_value_field;
        
    //      if (it->_M_left != 0)
    //        std::cout<< " left =" << it-> _M_left->_M_value_field; 
    //     else
    //         std::cout<< " left - nal ";
    //     if (it->_M_right != 0)
    //        std::cout<< " right =" << it-> _M_right->_M_value_field; 
    //     else
    //         std::cout<< " right - nal ";
    //     if (it-> _M_parent != 0)
    //        std::cout<< " par  =" << it-> _M_parent->_M_value_field;
    //     std::cout << "\n";
     
    //         std::cin >> h;
    //         if (h == 'w')
    //             it = it->_M_parent;
    //         if (h == 'a')
    //             it = it->_M_left;
    //         if (h == 'd')
    //             it = it->_M_right;
    //         if (h == 'q')
    //             return;
    //     }
    // }
};


}
#endif