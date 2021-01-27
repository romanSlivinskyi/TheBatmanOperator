/* The wrapper that makes thread-safe access to*/
   

template<typename T, typename L>
struct SafeGuard
{
    auto operator ++(int) { 
        struct _{
            _(T &t, L &l) : _t(t), _l(l) { _l.lock(); }
            ~_() { _l.unlock(); }   
            T& operator++() { return _t; }
            T &_t;
            L &_l;
        } __(*((T*)this), _l); 
        return __;
    }      
  private:
    L _l;
};
