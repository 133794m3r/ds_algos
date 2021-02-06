cmake_minimum_required(VERSION 3.18)
project(ds_algos)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD  C99)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++11 /W4")
	set(CMAKE_CXX_FLAGS_RELEASE "{CMAKE_CXX_FLAGS_RELEASE} /O2")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -O0 -g3 ")
	#since CLion decides that you debug from the damn release buildl always instead of from debug and won't let you change that.
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")

	if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	endif()
endif()

add_executable(sort_tests
		algos/sorting/sort_algos.hxx
		algos/sorting/sort_tests.cpp)

add_executable(linked_list
		data_structures/linked_list/d_linked_list.hxx
		data_structures/linked_list/linked_list.hxx
		data_structures/linked_list/linked_list_test.cpp )

add_executable(queue_test
		data_structures/queue/queue.hxx
		data_structures/queue/queue_test.cpp)

add_executable(stack_test
		data_structures/stack/stack.hxx
		data_structures/stack/stack_test.cpp)

add_executable(bst_test
		data_structures/binary_search_tree/bst_test.cpp
		data_structures/binary_search_tree/bst.hxx)

add_executable(hashtable_test
		data_structures/hashtable/hashtable.hxx
		data_structures/hashtable/hashtable_test.cpp)

add_executable(graph_test
		data_structures/graph/graph_test.cpp
		data_structures/graph/graph.hxx)

add_executable(max_heap_test
		data_structures/heaps/maxbinary_test.cpp
		data_structures/heaps/maxbinary.hxx)

add_executable(priority_q_test
		data_structures/priority_q/priorityq_test.cpp
		data_structures/priority_q/priorityq.hxx)
# still data structures for now
add_executable(dijsktra_test
		data_structures/weighted_graph/weighted_graph_test.cpp
		data_structures/weighted_graph/weighted_graph.hxx)