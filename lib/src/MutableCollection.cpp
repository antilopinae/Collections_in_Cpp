#include "Collection.h"
#include "MutableIterable.h"

template <class T>
class MutableCollection: protected Collection<T>, protected virtual MutableIterable<T>{
private:

public:

};
