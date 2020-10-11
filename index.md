# Asynchronous file system

```
@Def(file: asyncfs.h)
	#pragma once
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

