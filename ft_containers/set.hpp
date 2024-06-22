#ifndef FT_SET
#define FT_SET
#include "_r_b_tree.hpp"
namespace ft{
template<class Key,class Compare = std::less<Key>,class Allocator = std::allocator<Key>
> class set{
    private:
        _rb_tree<Key, Key,Compare,Allocator> _tree;
    public:
    typedef   _rb_tree<Key, Key,Compare,Allocator> TREE;
    
    typedef typename TREE::const_iterator const_iterator;
    typedef   const_iterator iterator;
    typedef typename TREE::const_reverse_iterator const_reverse_iterator;
    typedef const_reverse_iterator reverse_iterator;
    typedef Key key_type;
    typedef Key value_type;
    typedef typename TREE::size_type size_type;

    typedef Compare key_compare;
    typedef Compare value_compare;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename  allocator_type::pointer pointer;
    typedef typename 	allocator_type::const_pointer  const_pointer;
  
    typedef typename iterator_traits<iterator>::difference_type difference_type;


    Compare key_comp() const{
        return _tree.key_comp();
    }
    Compare value_comp() const{
        return _tree.key_comp();
    }

    void swap (set& x){
        _tree.swap(x._tree);
    }

    explicit
      set(const Compare& __comp = Compare(),
	  const allocator_type& __a = Allocator())
      : _tree(__comp, __a) { }
    template <class InputIterator>  
    set (InputIterator first, InputIterator last, 
          const Compare& comp = Compare(), 
          const allocator_type& alloc = Allocator()):_tree(comp, alloc) {
                while (first != last){
                    _tree.insert(*(first++));
                }
          }
    Allocator get_allocator() const{
        return _tree.get_allocator();
    }
    set (const set& x):_tree(x._tree._Compare, x._tree._Alloc_b){
        iterator i = x.begin();
        while(i != x.end()){
            _tree.insert(*(i++));
        }
    }
    set& operator=(const set& oth){
        if( this == &oth)
            return *this;
        _tree.clear();
        iterator i = oth.begin();
        while(i != oth.end()){
            _tree.insert(*(i++));
        }
         return *this;
    }
    void clear(){
        _tree.clear();
    }
    iterator lower_bound (const value_type& val) const{
        return _tree.lower_bound(val);
    }
     iterator upper_bound (const value_type& val) const{
         return _tree.upper_bound(val);
     }
    pair<iterator,iterator> equal_range (const value_type& val) const{
        return _tree.equal_range(val);
    }
    pair<iterator, bool> insert( const Key& value ){
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
    iterator find (const value_type& val) const{
        return _tree.find_iter(val);
    }
    template <class _Key, class _Compare, class _Allocator>
    friend bool    operator==(const set<_Key, _Compare, _Allocator>& __x,
           const set<_Key, _Compare, _Allocator>& __y);
   

};
template <class _Key, class Compare, class Allocator>

bool    operator==(const set<_Key, Compare, Allocator>& __x,
           const set<_Key, Compare, Allocator>& __y)
{
        return __x._tree == __y._tree;
}

   template <class _Key, class _Compare, class _Allocator>
     bool    operator<(const set<_Key, _Compare, _Allocator>& lhs,
           const set<_Key, _Compare, _Allocator>& rhs)
           {
                 return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    
           }
      template <class _Key, class _Compare, class _Allocator>
     bool    operator>(const set<_Key, _Compare, _Allocator>& rhs,
           const set<_Key, _Compare, _Allocator>& lhs)
           {
                 return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    
           }
     template <class _Key, class _Compare, class _Allocator>
     bool    operator<=(const set<_Key, _Compare, _Allocator>& rhs,
           const set<_Key, _Compare, _Allocator>& lhs)
           {
                 return rhs <lhs ||rhs == lhs;
    
           }
           template <class _Key, class _Compare, class _Allocator>
     bool    operator>=(const set<_Key, _Compare, _Allocator>& rhs,
           const set<_Key, _Compare, _Allocator>& lhs)
           {
                 return rhs >lhs ||rhs == lhs;
           }
             template <class _Key, class _Compare, class _Allocator>
     bool    operator!=(const set<_Key, _Compare, _Allocator>& rhs,
           const set<_Key, _Compare, _Allocator>& lhs)
           {
                 return  ! (rhs ==lhs);
           }
    template< typename A,typename B, typename C>
    void swap (set<A,B,C>& x,set<A,B,C> &y){
        x.swap(y);
    }

}
#endif