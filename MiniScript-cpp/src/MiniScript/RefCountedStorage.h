//
//  RefCountedStorage.h
//  MiniScript
//
//  Created by Joe Strout on 6/1/18.
//  Copyright © 2018 Joe Strout. All rights reserved.
//

#ifndef REFCOUNTEDSTORAGE_H
#define REFCOUNTEDSTORAGE_H

#include <stdio.h>

namespace MiniScript {
	
	class RefCountedStorage {
	public:
		void retain() { refCount++; }
		void release() { if (--refCount == 0) delete this; }
		
	protected:
		RefCountedStorage() : refCount(1) {
#if(DEBUG)
			instanceCount++;
			printf("+++ %ld instances\n", instanceCount);
#endif
		}
		virtual ~RefCountedStorage() {
#if(DEBUG)
			instanceCount--;
			printf("--- %ld instances\n", instanceCount);
#endif
		}
		
		long refCount;
		
#if(DEBUG)
	public:
		static long instanceCount;
#endif
	};
	

}
#endif /* REFCOUNTEDSTORAGE_H */
