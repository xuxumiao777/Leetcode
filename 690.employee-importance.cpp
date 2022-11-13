/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    Employee* findEmployee(vector<Employee*> employees,int id){
        for(int i=0;i<employees.size();i++){
            if(employees[i]->id==id){
                return employees[i];
            }
        }
        return NULL;
    }
    int getImportance(vector<Employee*> employees, int id) {
        //sort(employees.begin(),employees.end(),[](Employee *a,Employee *b){return a->id<b->id;});
        int res=findEmployee(employees,id)->importance;
        queue<int> q;
        int size=findEmployee(employees,id)->subordinates.size();
        for(int i=0;i<size;i++){
            q.push(findEmployee(employees,id)->subordinates[i]);
        }
        while(!q.empty()){
            id=q.front();
            Employee *cur=findEmployee(employees,id);
            size=cur->subordinates.size();
            res+=cur->importance;
            for(int i=0;i<size;i++){
                q.push(cur->subordinates[i]);
            }
            q.pop();            
        }
        return res;
    }
};