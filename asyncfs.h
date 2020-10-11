
#line 4 "index.md"

	#pragma once
	
#line 36 "index.md"

	#include <cstring>

#line 6 "index.md"

	namespace asyncfs {
		
#line 42 "index.md"

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

#line 8 "index.md"

	};
