
Pod::Spec.new do |s|
  s.name          = 'react-native-aes-cipher'
  s.version       = '1.0.0'
  s.summary       = 'Native module for AES encryption'
  s.author        = "nixstory@gmail.com"
  s.license       = 'MIT'
  s.requires_arc  = true
  s.homepage      = "https://github.com/reactspring/react-native-aes-cipher"
  s.source        = { :git => 'https://github.com/reactspring/react-native-aes-cipher' }
  s.platform      = :ios, '9.0'
  s.source_files  = "ios/**/*.{h,m}"

  s.dependency "React"
end
