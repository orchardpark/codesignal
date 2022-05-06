vector<int> solution(int lastBackupTime, vector<vector<int>> changes) {
    set<int> backup_items;
    for(auto change : changes){
        if(change[0]>lastBackupTime) backup_items.insert(change[1]);
    }
    vector<int> res;
    res.assign(backup_items.begin(),backup_items.end());

    return res;
}

