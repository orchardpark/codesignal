class WriterView
{
  public:
  WriterView(int writer, int views) : _writer(writer),  _views(views) {}
  int _writer;
  int _views;
  
  bool operator < (const WriterView& other) const
  {
      if(this->_views==other._views) return this->_writer < other._writer;
      return this->_views > other._views;
  }
  
  vector<int> to_vector()
  {
      vector<int> res;
      res.emplace_back(_writer);
      res.emplace_back(_views);
      return res;
  }
};

vector<vector<vector<int>>> solution(vector<vector<int>> topicIds, vector<vector<int>> answerIds, vector<vector<int>> views) {
    // mapping topicid -> writerid -> viewcount
    map<int, map<int, int>> viewsPerTopicPerWriter;
    
    for(auto topicList : topicIds){
        for(auto topic : topicList)
        {
            if(viewsPerTopicPerWriter.find(topic)==viewsPerTopicPerWriter.end()) viewsPerTopicPerWriter[topic] = map<int, int>();
        }
    }
    
    for(auto view : views)
    {
        int answerId = view[0];
        int writer = view[1];
        int viewCount = view[2];
        for(int i=0; i<answerIds.size(); i++)
        {
            auto answers = answerIds[i];
            if(find(answers.begin(), answers.end(), answerId) != answers.end())
            {
                for(auto topic : topicIds[i])
                {
                    if(viewsPerTopicPerWriter[topic].find(writer)==viewsPerTopicPerWriter[topic].end()) viewsPerTopicPerWriter[topic][writer] = 0;
                    viewsPerTopicPerWriter[topic][writer]+=viewCount;
                }
                break;
            }
        }
    }
    vector<vector<vector<int>>> res;
    for (auto topic : viewsPerTopicPerWriter)
    {
        vector<WriterView> viewsPerWriterW;
        for(auto viewsPerWriter : topic.second)
        {
            viewsPerWriterW.push_back(WriterView(viewsPerWriter.first, viewsPerWriter.second));
        }
        sort(viewsPerWriterW.begin(), viewsPerWriterW.end());
        vector<vector<int>> viewsPerWriter;
        for(auto writerview : viewsPerWriterW)
        {
            viewsPerWriter.push_back(writerview.to_vector());
        }
        
        res.push_back(viewsPerWriter);
    }
    return res;
    
    

}

