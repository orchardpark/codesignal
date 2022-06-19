vector<vector<string>> solution(vector<vector<string>> menu, int numberOfItems) {
    const string SECTION_HEADER = "Section Header";
    const string MENU_ITEM = "Menu Item";
    vector<vector<string>> res;
    vector<string> page;
    for(int i=0; i<menu.size(); i++)
    {
        auto menuItem = menu[i];
        // always add first item
        if(page.size()==0)
        {
            page.push_back(menuItem[0]);
        }
        // full page
        else if(page.size()==numberOfItems)
        {
            res.push_back(page);
            page = vector<string>();
            page.push_back(menuItem[0]);
        }
        else{
            // check if windowed
            if(menuItem[1]==SECTION_HEADER && page.size()==numberOfItems-1)
            {
                res.push_back(page);
                page = vector<string>();
                page.push_back(menuItem[0]);
            }
            // check if orphaned
            else if(
                (page.size()==numberOfItems-1 && i==menu.size()-2) ||
                (page.size()==numberOfItems-1 && i<menu.size()-2 && menuItem[1]==MENU_ITEM && menu[i+1][1]==MENU_ITEM && menu[i+2][1] == SECTION_HEADER)
            
            ){
                res.push_back(page);
                page = vector<string>();
                page.push_back(menuItem[0]);
            }
            else{
                page.push_back(menuItem[0]);
            }
        }
    }
    if(page.size()>0)res.push_back(page);

    return res;
}
