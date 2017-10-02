class ExtensionConfig

  require 'mkmf'

  extension_name = 'CFixedArray'

  dir_config(extension_name)

  create_makefile(extension_name)

end