# Asynchronous file system

```
@Def(file: asyncfs.h)
	#pragma once
	@put(includes)
	namespace asyncfs {
		@put(globals)
	};
@End(file: asyncfs.h)
```

```
@Def(file: asyncfs.cpp)
	#define async_IMPL 1
	#include "asyncfs.h"
@End(file: asyncfs.cpp)
```

```
@Def(file: asyncfs-tests.cpp)
	#define async_TESTS 1
	#include "asyncfs.h"
	int main() {
		@Put(run unit-tests)
	}
@End(file: asyncfs-tests.cpp)
```

```
@Def(run unit-tests)
@End(run unit-tests)
```

```
@def(includes)
	#include <cstring>
@end(includes)
```

```
@def(globals)
	class Dir_Entry {
		char name_[32];
	protected:
		Dir_Entry(const char *name);
		virtual ~Dir_Entry() {}
	public:
		class Name_Too_Long {};
		const char *name() const {
			return name_;
		}
	};
	inline Dir_Entry::Dir_Entry(const char *name) {
		strncpy(name_, name, sizeof(name_));
		if (name_[sizeof(name_) - 1]) {
			throw Name_Too_Long {};
		}
	}
	class Dir: public Dir_Entry {
		Dir *parent_;
	protected:
		Dir(const char *name, Dir *parent);
	public:
		static Dir &root();
		Dir *parent() const { return parent_; }
	};
	inline Dir::Dir(const char *name, Dir *parent):
		Dir_Entry { name }
	{
		parent_ = parent;
	}
	inline Dir &Dir::root() {
		static Dir root_ { "", nullptr };
		return root_;
	}
	class File: public Dir_Entry {
	};
@end(globals)
```
