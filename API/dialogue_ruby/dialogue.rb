require 'sinatra'
before do
    content_type :json
  end
  
  get '/' do
    { a: 1 }
  end

  get '/frank-says' do
    'Put this in your pipe & smoke it!'
  end
  
  after do
    response.body = JSON.dump(response.body)
  end
