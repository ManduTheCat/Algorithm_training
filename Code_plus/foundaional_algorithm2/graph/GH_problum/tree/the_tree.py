from sys import stdin

node, edge, root_num = map(int, stdin.readline().split())
check_dfs = [0] * (node * 2) #dfs 체크
adj_list = [[]for _ in range(node * 2)] #인접리스트
parents = [0] * (node * 2) #부모를 기록하는 리스트

def print_back(start_vertex, node_value_list): #뒤로 돌면서 출력하는 함수
	next = parents[start_vertex]
	if next == -1:
		return;
	print(node_value_list[next], end ="")
	print_back(next, node_value_list)

def back_dfs(cur_vertex, node_value_list, route_list, depth, flag): #뒤로 돌면서 rouet_list = 3 4 5 를 확인하는 함수
	parents_value = parents[cur_vertex]
	if(parents_value == -1 and depth - 1 == 0):
		flag  = 1
		return flag
	elif(node_value_list[cur_vertex] == route_list[depth - 1]):
		depth -= 1
		flag = back_dfs(parents_value, node_value_list, route_list, depth, flag)
		return flag

def dfs(cur_vertex, node_value_list, route_list, route_len): #전체 를 도는 main dfs
	check_dfs[cur_vertex] = 1
	flag  = 0 # flag 의 초기값
	if node_value_list[cur_vertex] == route_list[route_len - 1]:
		#dfs 가 5 를만나면 뒤로 돌아가면서 3 4 5 = route_list  가 맞는 지 확인한다
		#맞으면 now_flag 는 1 이되고 아니면 None 이다
		new_flag= back_dfs(cur_vertex, node_value_list, route_list ,route_len, flag)
		if(new_flag == 1):
			print(node_value_list[cur_vertex], end ="") #route 존재하면 현재 노드 출수
			print_back(cur_vertex, node_value_list) # 부모 따라가면서 뿌리에 닿으면 출력하는 함수
	for i in range (len(adj_list[cur_vertex])):
		next = adj_list[cur_vertex][i] #인접리스트를 활용한 dfs 부분
		if(check_dfs[next] == 0):
			parents[next] = cur_vertex #부모노드를 기록하는 부분
			dfs(next, node_value_list, route_list, route_len)

def main():
	adj_list_input = list()
	i = edge
	while i != 0:
		i -= 1
		adj_list_input.append(list(map(int , stdin.readline().split())))

	for from_node, to_node in adj_list_input:
		adj_list[from_node].append(to_node)

	node_value = list(map(int, stdin.readline().split()))
	node_value.insert(0, 0) #node_value 의 인덱스는 node 번호 , node 번호와 해당 값을 맞추기 위해 맨앞에 0 삽입
							#원래 index 0 = 3, index 1 = 2 -> index 1 = 3 index 2 = 2
	route_len = int(input())
	route_list = list(map(int, stdin.readline().split()))
	parents[1] = -1 #뿌리의 부모는  -1

	dfs(1,node_value, route_list,route_len)

if __name__ == "__main__":
	main()
