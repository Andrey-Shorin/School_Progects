#ifndef FT_MAP
#define FT_MAP
#include "_r_b_tree.hpp"
namespace ft{
    template <class pair,class key, class comp>
struct comp_ft 
{
    comp COMP;
    comp_ft(comp a):COMP(a){}
    comp_ft():COMP(comp()){}
    bool operator()(const pair& __x, const pair& __y) const
        {return COMP(__x.first , __y.first);}
    bool operator()(const pair& __x, const key& __y) const
        {return COMP(__x.first , __y);}
    bool operator()(const key& __x, const pair& __y) const
        {return COMP(__x , __y.first);}
    bool operator()(const key& __x, const key& __y) const
        {return COMP(__x , __y);}
};
template<class Key,class T,class Compare0 = std::less<Key>,class Allocator = std::allocator<pair<const Key,T> >
> class map{
    public:
    typedef comp_ft<pair<const Key,T>,Key,Compare0> Compare;
     typedef pair<const Key, T> value_type;
    private:
        _rb_tree<value_type,Key,Compare,Allocator> _tree;
    public:
    typedef   _rb_tree<value_type,Key,Compare,Allocator> TREE;
    typedef typename TREE::iterator iterator;
    typedef typename TREE::const_iterator const_iterator;
    typedef typename TREE::reverse_iterator reverse_iterator;
    typedef typename TREE::const_reverse_iterator const_reverse_iterator;
    
    typedef Key key_type;
    typedef T mapped_type;
    typedef typename TREE::size_type size_type;

    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer  const_pointer;
  
    typedef typename iterator_traits<iterator>::difference_type difference_type;
  

    Compare key_comp() const{
        return _tree.key_comp();
    }
    Compare value_comp() const{
        return _tree.key_comp();
    }

    void swap (map& x){
        _tree.swap(x._tree);
    }

    explicit
      map(const Compare0& __comp = Compare0(),
	  const allocator_type& __a = Allocator())
      : _tree(comp_ft<pair<const Key,T>,Key,Compare0>(__comp), __a) { }
    template <class InputIterator>  
    map (InputIterator first, InputIterator last, 
          const Compare0& comp = Compare0(), 
          const allocator_type& alloc = Allocator()):_tree(comp_ft<pair<const Key,T>,Key,Compare0>(comp), alloc) {
                while (first != last){
                    _tree.insert(*(first++));
                }
          }
    Allocator get_allocator() const{
        return _tree.get_allocator();
    }
    map (const map& x):_tree(x._tree._Compare, x._tree._Alloc_b){
        const_iterator i = x.begin();
        while(i != x.end()){
            _tree.insert(*(i++));
        }
    }
    map& operator=(const map& oth){
        if( this == &oth)
            return *this;
        _tree.clear();
        const_iterator i = oth.begin();
        while(i != oth.end()){
            _tree.insert(*(i++));
        }
         return *this;
    }
    void clear(){
        _tree.clear();
    }
     mapped_type& at (const key_type& k){
         
         value_type * f = _tree.find(k);
         if (f == 0)
            throw(std::out_of_range("not found"));
        return (* f).second;

     }
     
     
     const mapped_type& at (const key_type& k) const{
             value_type * f = _tree.find(k);
         if (f == 0)
            throw(std::out_of_range("not found"));
        return (* f).second;
     }
    const_iterator lower_bound (const key_type& val) const{
        return _tree.lower_bound(val);
    }
    iterator lower_bound (const key_type& val) {
        return _tree.lower_bound(val);
    }
     const_iterator upper_bound (const key_type& val) const{
         return _tree.upper_bound(val);
     }
     iterator upper_bound (const key_type& val) {
         return _tree.upper_bound(val);
     }
    pair<iterator,iterator> equal_range (const key_type& val){
        return _tree.equal_range(val);
    }
    pair<const_iterator,const_iterator> equal_range (const key_type& val) const{
        return _tree.equal_range(val);
    }



    pair<iterator, bool> insert( const value_type& value ){

        return _tree.insert(value);
    }
    iterator insert (iterator position, const value_type& val){
        (void) position;
        pair<iterator, bool> a;
        a = insert(val);
            return a.first;

    }
    template< class InputIt >
    void insert( InputIt first, InputIt last ){
        while(first != last){
            insert(*first);
            first++;
        }
}
size_type count( const Key& key ) const{
    return _tree.count(key);
}
    iterator begin(){
        return _tree.begin();
    }
    const_iterator begin() const{
        return _tree.begin();
    }
    iterator end(){
        return _tree.end();
    }
    const_iterator end() const{
        return _tree.end();
    }
    reverse_iterator rbegin(){return reverse_iterator(_tree.end());}
    reverse_iterator rend(){return reverse_iterator(_tree.begin());}
        const_reverse_iterator rbegin() const {return  const_reverse_iterator(_tree.end());}
     const_reverse_iterator rend() const {return  const_reverse_iterator(_tree.begin());}
    size_t size() const{
            return _tree.size();
    }
    bool empty() const{
            return  _tree.empty();
    }
    size_t max_size() const{
            return 
              std::numeric_limits<difference_type >::max() / (sizeof(typename TREE::_node) / 2); 
    
    }
    void erase( iterator pos ){
        _tree.erase(pos);
    }
    size_type erase( const Key& key ){
       return  _tree.erase(key);
    }
    void erase (iterator first, iterator last){
        iterator a = first;
        while (first != last){
           a = first;
           first ++;
           erase(a);
        }
    }
    mapped_type& operator[] (const key_type& k){
        value_type * f = _tree.find(k);
        if ( f != 0)
            return ( *f).second; 
        iterator i = _tree.insert(value_type(k,T())).first;
        return (*i).second;
        
    }
    iterator find (const key_type& k){
        return _tree.find_iter(k);
    }
    const_iterator find (const key_type& k) const{
        return _tree.find_iter(k);
    }
    template <class _Key, class _T,class _Compare, class _Allocator>
    friend bool    operator==(const map<_Key,_T, _Compare, _Allocator>& __x,
           const map<_Key,_T, _Compare, _Allocator>& __y);
   

};
template <class _Key,class T, class Compare, class Allocator>

bool    operator==(const map<_Key,T, Compare, Allocator>& __x,
           const map<_Key,T, Compare, Allocator>& __y)
{
        return __x._tree == __y._tree;
}

   template <class _Key,class T, class _Compare, class _Allocator>
     bool    operator<(const map<_Key,T, _Compare, _Allocator>& lhs,
           const map<_Key,T, _Compare, _Allocator>& rhs)
           {
                 return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    
           }
      template <class _Key, class T,class _Compare, class _Allocator>
     bool    operator>(const map<_Key,T, _Compare, _Allocator>& rhs,
           const map<_Key,T, _Compare, _Allocator>& lhs)
           {
                 return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    
           }
     template <class _Key,class T, class _Compare, class _Allocator>
     bool    operator<=(const map<_Key,T, _Compare, _Allocator>& rhs,
           const map<_Key,T, _Compare, _Allocator>& lhs)
           {
                 return rhs <lhs ||rhs == lhs;
    
           }
           template <class _Key, class T,class _Compare, class _Allocator>
     bool    operator>=(const map<_Key,T, _Compare, _Allocator>& rhs,
           const map<_Key,T, _Compare, _Allocator>& lhs)
           {
                 return rhs >lhs ||rhs == lhs;
           }
             template <class _Key, class T,class _Compare, class _Allocator>
     bool    operator!=(const map<_Key,T, _Compare, _Allocator>& rhs,
           const map<_Key,T, _Compare, _Allocator>& lhs)
           {
                 return  ! (rhs ==lhs);
           }
    template< typename A,typename r,typename B, typename C>
    void swap (map<A,r,B,C>& x,map<A,r,B,C> &y){
        x.swap(y);
    }

}
#endif